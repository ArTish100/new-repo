//Print all the subsequences

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int dfs(int a, vector<int> &vec, vector<int> dstr, int target, vector<vector<int>> &ans, int &vlen, int sum){
        if(a==vlen){
            if(sum==target){
                ans.push_back(dstr);
                return 1;
            }
            return 0;
        }
        dstr.push_back(vec[a]);
        sum+=vec[a];
        int l = dfs(a+1, vec, dstr, target, ans, vlen, sum);
        dstr.pop_back();
        sum-=vec[a];
        int r = dfs(a+1, vec, dstr, target, ans, vlen, sum);
        return l+r;
    }
    vector<vector<int>> printAllSubs(vector<int> vec, int target){
        int ind = 0;
        vector<vector<int>> ans;
        int vlen = vec.size();
        vector<int> datastr;
        int sum = 0;
        cout<<dfs(ind, vec, datastr, target, ans, vlen, sum)<<endl;
        return ans;
    }
    void printVec(vector<vector<int>> vec){
        for(auto b : vec){
            for(int a : b)
                cout<<a<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Solution S;
    vector<int> vec = {4, 2, 10, 5, 1, 3};
    int target = 5;
    vector<vector<int>> ans = S.printAllSubs(vec, target);
    S.printVec(ans);
}
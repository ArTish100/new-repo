//39. Combination Sum

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>> &uset, vector<int> dstr, int ind, int sum, int clen){
        if(ind==clen){
            if(sum==target){
                uset.push_back(dstr);
            }
            return;
        }
        dstr.push_back(candidates[ind]);
        dfs(candidates, target, uset, dstr, ind+1, sum+candidates[ind], clen);
        dstr.pop_back();
        dfs(candidates, target, uset, dstr, ind+1, sum, clen);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> dstr;
        int clen = candidates.size();
        dfs(candidates, target, ans, dstr, 0, 0, clen);
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
    vector<int> vec = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = S.combinationSum(vec, target);
    S.printVec(ans);
}
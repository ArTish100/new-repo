//Subset Sum : Sum of all Subsets

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void printVec(vector<int> vec){
        for(int a : vec){
            cout<<a<<" ";
        }
    }

    void dfs(vector<int> &vec, vector<int> &ans, int dstr, int ind){
        if(ind>=vec.size()){
            ans.push_back(dstr);
            return;
        }
        dfs(vec,ans,dstr+vec[ind],ind+1);
        dfs(vec,ans,dstr,ind+1);
    }

    vector<int> sumofsubs(vector<int> vec){
        vector<int> ans;
        dfs(vec,ans, 0, 0);
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {3,1,2};
    vector<int> ans = S.sumofsubs(vec);
    S.printVec(ans);
}
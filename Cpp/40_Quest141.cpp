//39. Combination Sum II

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> dstr, int ind){
        if(!target){
            ans.push_back(dstr);
            return;
        }
        int clen = candidates.size();
        for(int i=ind;i<clen;i++){
            if(i > ind && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            dstr.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], ans, dstr, i+1);
            dstr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> dstr;
        sort(candidates.begin(),candidates.end());
        dfs(candidates, target, ans, dstr, 0);
        return ans;
    }
    void dfs1(vector<int>& candidates, int target, set<vector<int>> &uset, vector<int> dstr, int ind, int sum, int clen){
        if(ind==clen){
            if(sum==target){
                uset.insert(dstr);
            }
            return;
        }
        dstr.push_back(candidates[ind]);
        dfs1(candidates, target, uset, dstr, ind+1, sum+candidates[ind], clen);
        dstr.pop_back();
        dfs1(candidates, target, uset, dstr, ind+1, sum, clen);
    }
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> dstr;
        int clen = candidates.size();
        sort(candidates.begin(),candidates.end());
        set<vector<int>> uset;
        dfs1(candidates, target, uset, dstr, 0, 0, clen);
        for(vector<int> it : uset){
            ans.push_back(it);
        }
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
    vector<vector<int>> ans = S.combinationSum2(vec, target);
    S.printVec(ans);
}
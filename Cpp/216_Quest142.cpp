//216. Combination Sum III

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void printVec(vector<vector<int>> vec){
        for(auto a : vec){
            for(int b : a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
    }
    void printVecLin(vector<int> vec){
        for(auto b : vec){
                cout<<b<<" ";
        }
        cout<<endl;
    }
    void dfs(int k, int n, vector<vector<int>> &ans, vector<int> dstr, int ind){
        if(!n && dstr.size()==k){
            ans.push_back(dstr);
            return;
        }
        if(ind>9 || n<=0)
            return;
        dstr.push_back(ind);
        dfs(k, n-ind, ans, dstr, ind+1);
        dstr.pop_back();
        dfs(k, n, ans, dstr, ind+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> dstr;
        dfs(k, n, ans, dstr, 1);
        return ans;
    }
};

int main(){
    Solution S;
    vector<vector<int>> ans = S.combinationSum3(4,1);
    S.printVec(ans);
}
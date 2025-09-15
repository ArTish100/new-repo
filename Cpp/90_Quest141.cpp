//90. Subsets II

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
    void dfs(vector<vector<int>> &ans , vector<int> subsadd, vector<int> &nums, int ind){
        ans.push_back(subsadd);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            subsadd.push_back(nums[i]);
            dfs(ans, subsadd, nums, i+1);
            subsadd.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> subsadd;
        dfs(ans, subsadd, nums, 0);
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {1,2,2};
    vector<vector<int>> ans = S.subsetsWithDup(vec);
    S.printVec(ans);
}
//78. Subsets

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    void addsubs(int ind, vector<int> &subset, vector<vector<int>> &ans, vector<int>& nums){
        if(ind==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        addsubs(ind+1, subset, ans, nums);
        subset.pop_back();
        addsubs(ind+1, subset, ans, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        addsubs(0,subset, ans, nums);
        return ans;
    }   

    void printVec(vector<vector<int>> vec){
        for(auto a : vec){
            for(int b : a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3};
    vector<vector<int>> ans = S.subsets(vec);
    S.printVec(ans);
}
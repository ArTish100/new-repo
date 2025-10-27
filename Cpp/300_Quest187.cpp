//300. Longest Increasing Subsequence

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<climits>

using namespace std;

class Solution {
    public:
    
    void printVector(vector<int> vector){
        for(int a:vector)
            cout<<a<<" ";
        cout<<endl;
    }

    int memoizWay(vector<int>& nums, int ind, vector<vector<int>> &dp, int prev, int n){
        if(ind==n)
            return 0;
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        int r1=memoizWay(nums, ind+1, dp, prev, n);
        int r2=0;
        if(prev==-1 || nums[ind]>nums[prev])
            r2=1+memoizWay(nums, ind+1, dp, ind, n);
        return dp[ind][prev+1] = max(r1,r2);
    }

    int recurWay(vector<int>& nums, int ind, int prev, int n){
        if(ind==n)
            return 0;
        int r1=recurWay(nums, ind+1, prev, n);
        int r2=0;
        if(prev==-1 || nums[prev]<nums[ind])
            r2=1+recurWay(nums, ind+1, ind, n);
        return max(r1,r2);
    }

    void allDPWays(vector<int>& nums) {
        int n=nums.size();
        cout<<recurWay(nums, 0, -1, n)<<endl;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // cout<<getAns(nums, n, 0, -1, dp)<<endl;
         vector<vector<int>> dp2(n,vector<int>(n,-1));
        cout<<memoizWay(nums, 0, dp2, -1, n)<<endl;
        // cout<<tabulationWay(nums);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            // vector<int> vec;
            // vec.push_back(nums[ptr]);
            for(int j=0;j<i;j++){
                int r1=dp[i];
                int r2=0;
                if(nums[i]>nums[j]){
                    r2=1+dp[j];
                }
                dp[i]=max(r1,r2);
            }
            // printVector(vec);
        }
        int maxi=INT_MIN;
        for(int a:dp)
            maxi=max(maxi,a);
        return maxi;
    }
};

int main(){
    vector<int> nums={10,9,2,5,3,7,101,18,20};
    // vector<int> nums={0,1,0,3,2,3};
    // vector<int> nums={7,7,7,7,7,7,7};
    // vector<int> nums={6,7,8,7};
    Solution S;
    S.allDPWays(nums);
    S.lengthOfLIS(nums);

}
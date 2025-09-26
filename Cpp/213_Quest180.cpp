//213. House Robber II

#include<iostream>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<int> &nums){
        int nlen = nums.size();
        if(nlen==1)
            return nums[0];
        int curr1;
        int curr2;
        vector<int> dp(nlen,-1);
        dp[0] = nums[0];
        for(int i=1;i<nlen-1;i++){
            if(i-2>=0)
                curr1 = nums[i] + dp[i-2];
            else
                curr1 = nums[i];
            curr2 = dp[i-1];
            dp[i] = max(curr1,curr2);
        }
        int ans1 = dp[nlen-2];
        if(nlen>1)
            dp[1] = nums[1];
        for(int i=2;i<nlen;i++){
            if(i-2>0)
                curr1 = nums[i] + dp[i-2];
            else
                curr1 = nums[i];
            curr2 = dp[i-1];
            dp[i] = max(curr1,curr2);
        }
        return max(dp[nlen-1],ans1);
    }
    int memoizWay(vector<int> &vec, vector<int> &dp, int ind, int start){
        if(start == 0){
            if(ind == 0)
                return vec[0];
            if(ind < 0)
                return 0;
        }
        if(start == 1){
            if(ind == 1)
                return vec[1];
            if(ind < 1)
                return 0;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        int curr1;
        int curr2;
        curr1 = vec[ind] + memoizWay(vec, dp, ind-2, start);
        curr2 = memoizWay(vec, dp, ind-1, start);
        return dp[ind] = max(curr1,curr2);
        
    }
    int recurWay(vector<int> &vec, int ind, int start){
        if(start == 0){
            if(ind == 0)
                return vec[0];
            if(ind < 0)
                return 0;
        }
        if(start == 1){
            if(ind == 1)
                return vec[1];
            if(ind < 1)
                return 0;
        }
        int curr1;
        int curr2;
        curr1 = vec[ind] + recurWay(vec, ind-2, start);
        curr2 = recurWay(vec, ind-1, start);
        return max(curr1,curr2);
    }
    void robber(vector<int> nums){
        int nlen = nums.size();
        vector<int> dp(nlen, -1);
        // cout<<max(recurWay(nums, nlen-1, 1),recurWay(nums, nlen-2, 0))<<endl;
        cout<<max(memoizWay(nums, dp, nlen-1, 1),memoizWay(nums, dp, nlen-2, 0))<<endl;
        cout<<tabulation(nums)<<endl;
    }
    int rob(vector<int>& nums) {
        int nlen = nums.size();
        if(nlen==1)
            return nums[0];
        int curr1;
        int curr2;
        int ans = nums[0];
        for(int i=1;i<nlen-1;i++){
            if(i-2>=0)
                curr1 = nums[i] + curr2;
            else
                curr1 = nums[i];
            curr2 = ans;
            ans = max(curr1,curr2);
        }
        int ans1 = ans;
        if(nlen>1)
            ans = nums[1];
        for(int i=2;i<nlen;i++){
            if(i-2>0)
                curr1 = nums[i] + curr2;
            else
                curr1 = nums[i];
            curr2 = ans;
            ans = max(curr1,curr2);
        }
        return max(ans,ans1);
    }
};

int main(){
    Solution S;
    vector<int> vec = {2,3,2};
    // vector<int> vec = {1,2,3,1};
    // vector<int> vec = {1,2,3};
    // vector<int> vec = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,
    //     225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,
    //     103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,
    //     120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
    S.robber(vec);
    cout<<S.rob(vec);
}


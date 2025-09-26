//198. House Robber

#include<iostream>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<int> &nums){
        int vlen = nums.size();
        vector<int> dp(vlen,-1);
        int curr1;
        int curr2;
        dp[0] = nums[0];
        for(int i=1;i<vlen;i++){
            if(i-2>=0)
                curr2 = nums[i] + dp[i-2];
            else
                curr2 = nums[i];
            curr1 = dp[i-1];
            dp[i] = max(curr1,curr2);
        }
        return dp[vlen-1];
    }
    int memoizWay(vector<int> &vec, vector<int> &dp, int ind){
        if(ind==0)
            return vec[0];
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int curr2 = memoizWay(vec,dp,ind-2) + vec[ind];
        int curr3 = memoizWay(vec,dp,ind-1);            
        return  dp[ind] = max(curr2,curr3);
    }
    int recurWay(vector<int> &vec, int ind){
        if(ind==0)
            return vec[0];
        if(ind<0)
            return 0;
        int curr2 = recurWay(vec, ind-2) + vec[ind];
        int curr3 = recurWay(vec, ind-1);
        return max(curr2,curr3);
    }
    void robber(vector<int> nums){
        vector<int> dp(nums.size(), -1);
        cout<<recurWay(nums, nums.size()-1)<<endl;
        cout<<memoizWay(nums, dp, nums.size()-1)<<endl;
        cout<<tabulation(nums)<<endl;
    }
    int rob(vector<int>& nums) {
        int curr1 = nums[0];
        int curr2;
        int ans = nums[0];
        int nlen=nums.size();
        for(int i=1;i<nlen;i++){
            if(i-2>=0)
                curr2 = nums[i] + curr1;
            else
                curr2 = nums[i];
            curr1 = ans;
            ans = max(curr1,curr2);
        }
        return ans;
    }
};

int main(){
    Solution S;
    // vector<int> vec = {2,7,9,3,1};
    // vector<int> vec = {1,2,3,1};
    vector<int> vec = {1,2};
    // vector<int> vec = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,
    //     225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,
    //     103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,
    //     120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
    S.robber(vec);
    cout<<S.rob(vec);
}


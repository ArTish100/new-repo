//416. Partition Equal Subset Sum

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<climits>

using namespace std;

class Solution {
public:
    
    bool tabulation(vector<int>& nums, int sum) {
        int nlen=nums.size();
        vector<vector<int>> dp(nlen,vector<int>(sum+1, 0));
        for(int i=0;i<nlen;i++)
            dp[i][0]=true;
        if(nums[0]<=sum)
            dp[0][nums[0]]=true;
        int r1,r2;
        for(int i=1;i<nlen;i++){
            for(int target=1;target<=sum;target++){
                r1=dp[i-1][target];
                r2=false;
                if(nums[i]<=target)
                    r2=dp[i-1][target-nums[i]];
                dp[i][target] = r1||r2;
            }
        }
        return dp[nlen-1][sum];
    }
    
    bool memoizWay(vector<int>& nums, int target, vector<vector<int>> &dp, int ind) {
        if(target==0)
            return true;
        if(ind==0)
            return nums[0]==target;
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        bool r1=memoizWay(nums, target, dp, ind-1);
        bool r2=false;
        if(nums[ind]<=target)
            r2=memoizWay(nums, target-nums[ind], dp, ind-1);
        return dp[ind][target]=r1||r2;
    }

    bool recurWay(vector<int>& nums, int target, int ind) {
        if(target==0)
            return true;
        if(ind==0)
            return nums[0]==target;
        bool r1=recurWay(nums, target, ind-1);
        bool r2=false;
        if(nums[ind]<=target)
            r2=recurWay(nums, target-nums[ind], ind-1);
        return r1||r2;
    }

    void allDPWays(vector<int>& nums) {
        int nlen=nums.size();
        int sum=0;
        for(int a:nums)
            sum+=a;
        if(sum & 1)
            cout<<false<<endl;
        else{
            sum=sum/2;
            cout<<recurWay(nums, sum, nlen-1)<<endl;
            vector<vector<int>> dp(nlen,(vector<int>(sum+1,-1)));
            cout<<memoizWay(nums, sum, dp, nlen-1)<<endl;
            cout<<tabulation(nums, sum)<<endl;
        }
    }

    bool canPartition(vector<int>& nums) {
        int nlen=nums.size();
        int sum=0;
        for(int a:nums)
            sum+=a;
        if(sum & 1)
            return false;
        else{
            sum=sum/2;
            int nlen=nums.size();
            vector<bool> dp(sum+1, false);
            dp[0]=true;
            if(nums[0]<=sum)
                dp[nums[0]]=true;
            int r1,r2;
            for(int i=1;i<nlen;i++){
                vector<bool> curr(sum+1, false);
                curr[0]=true;
                for(int target=1;target<=sum;target++){
                    r1=dp[target];
                    r2=false;
                    if(nums[i]<=target)
                        r2=dp[target-nums[i]];
                    curr[target]=r1||r2;
                }
                dp=curr;
            }
            return dp[sum];
        }
        
    }
};

int main(){
    Solution S;
    // vector<int> nums={1,2,3,5};
    // vector<int> nums={7,4,5};
    vector<int> nums={1,5,11,5};
    S.allDPWays(nums);
    cout<<S.canPartition(nums)<<endl;
}
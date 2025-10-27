//Subset sum equal to target (DP- 14)

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<climits>

using namespace std;

class Solution {
public:
    
    bool tabulation(vector<int>& arr, int sum) {
        int alen=arr.size();
        vector<vector<bool>> dp(alen, vector<bool>(sum+1,false));
        for(int ind=0;ind<alen;ind++){
            dp[ind][0]=1;
        }
        if(arr[0]<=sum)
            dp[0][arr[0]]=1;
        bool r1,r2;
        for(int ind=1;ind<alen;ind++){
            for(int target=1;target<=sum;target++){
                r1=dp[ind-1][target];
                r2=false;
                if(arr[ind]<=target)
                    r2=dp[ind-1][target-arr[ind]];
                dp[ind][target]=r1 || r2;
            }
        }
        return dp[alen-1][sum];
    }
    
    bool memoizWay(vector<int>& arr, int sum, vector<vector<int>> &dp, int ind) {
        if(sum==0)
            return true;
        if(ind==0)
            return arr[0]==sum;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        bool r1=false;
        if(arr[ind]<=sum)
            r1=memoizWay(arr,sum-arr[ind],dp,ind-1);
        return dp[ind][sum]=(r1 || memoizWay(arr,sum,dp,ind-1));
    }

    bool recurWay(vector<int>& arr, int sum, int ind) {
        if(ind==0)
            return arr[0]==sum;
        if(sum==0)
            return true;
        bool r1=false;
        if(arr[ind]<=sum)
            r1=recurWay(arr, sum-arr[ind], ind-1);
        return r1 || recurWay(arr, sum, ind-1);
    }

    void allDPWays(vector<int>& arr, int sum) {
        int alen=arr.size();
        cout<<recurWay(arr, sum, alen-1)<<endl;
        vector<vector<int>> dp(alen,vector<int>(sum+1,-1));
        cout<<memoizWay(arr, sum, dp, alen-1)<<endl;
        cout<<tabulation(arr, sum)<<endl;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int alen=arr.size();
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        if(arr[0]<=sum)
            dp[arr[0]]=true;
        int r1,r2;
        for(int i=1;i<alen;i++){
            vector<bool> curr(sum+1,false);
            curr[0]=true;
            for(int target=1;target<=sum;target++){
                r1=dp[target];
                r2=false;
                if(arr[i]<=target)
                    r2=dp[target-arr[i]];
                curr[target]=r1||r2;
            }
            dp=curr;
        }
        return dp[sum];
    }
};

int main(){
    Solution S;
    // vector<int> arr={3, 34, 4, 12, 5, 2};
    vector<int> arr={7,4,5};
    int sum=2;
    S.allDPWays(arr, sum);
    cout<<S.isSubsetSum(arr, sum)<<endl;
}
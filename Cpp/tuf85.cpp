//Count Subsets with Sum K (DP - 17)

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<climits>

using namespace std;

class Solution {
public:
    
    int tabulation(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        if(arr[0]<=target)
            dp[0][arr[0]]=1;
        int r1,r2;
        for(int ind=1;ind<n;ind++){
            for(int t=1;t<=target;t++){
                r1=dp[ind-1][t];
                r2=0;
                if(arr[ind]<=t)
                    r2=dp[ind-1][t-arr[ind]];
                dp[ind][t]=r1+r2;
            }
        }
        return dp[n-1][target];
        
    }
    
    int memoizWay(vector<int>& arr, int target, vector<vector<int>> &dp, int ind) {
        if(target==0)
            return 1;
        if(ind==0)
            return arr[ind]==target;
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int r1=memoizWay(arr,target,dp,ind-1);
        int r2=0;
        if(arr[ind]<=target)
            r2=memoizWay(arr, target-arr[ind], dp, ind-1);
        return dp[ind][target]=r1+r2;}

    int recurWay(int i, int currentSum, int target, vector<int>& arr) {
        int n = arr.size();

        // Base case: If we've processed all elements 
        // in the array
        if (i == n) {
        
            // Return 1 if the current subset's
            // sum equals the target, else return 0
            return (currentSum == target);
        }

        // Case 1: Exclude the current element from the subset
        // and move to the next element
        int exclude = recurWay(i + 1, currentSum, target, arr);

        // Case 2: Include the current element in the subset
        int include = 0;

        // Only include the current element if adding it 
        // does not exceed the target sum
        if ((arr[i] + currentSum) <= target) {
            include = recurWay(i + 1, currentSum + arr[i], target, arr);
        }

        // Return the total count of subsets by 
        // summing both cases
        return (include + exclude);
    }

    void allDPWays(vector<int>& arr, int target) {
        int n=arr.size();
        cout<<recurWay(0, 0, target, arr)<<endl;
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        cout<<memoizWay(arr, target, dp, n-1)<<endl;
        cout<<tabulation(arr, target)<<endl;
    }

    int perfectSum(vector<int>& arr, int target) {
        // int n=arr.size();
        // vector<int> dp(target+1,0);
        // dp[0]=1;
        // if(arr[0]<=target)
        //     dp[arr[0]]=1;
        // int r1,r2;
        // for(int ind=1;ind<n;ind++){
        //     vector<int> curr(target+1,0);
        //     curr[0]=dp[0];
        //     for(int t=1;t<=target;t++){
        //         r1=dp[t];
        //         r2=0;
        //         if(arr[ind]<=t)
        //             r2=dp[t-arr[ind]];
        //         curr[t]=r1+r2;
        //     }
        //     dp=curr;
        // }
        // return dp[target];
        int n = arr.size();
    
        // dp[i] will store the number of subsets that sum up to i.
        vector<int> dp(target + 1, 0);

        // Base case: There is one way to make a sum of 0, which is by
        // choosing the empty subset.
        dp[0] = 1;

        // Process each number in the input array
        for (int i = 0; i < n; i++) {
            // We iterate backwards to prevent using the same element multiple times
            // in one subset. This ensures that when we calculate dp[t],
            // the value dp[t - arr[i]] is from the *previous* state (before
            // considering the current arr[i]).
            for (int t = target; t >= arr[i]; t--) {
                dp[t] = (dp[t] + dp[t - arr[i]]);
            }
        }

        return dp[target];
    }
};

int main(){
    Solution S;
    // vector<int> arr={5, 2, 3, 10, 6, 8}; int target=10;
    
    vector<int> arr={28, 4, 3, 27, 0, 24, 26}; int target=24;
    // vector<int> arr={0,1,3}; int target=4;

    // vector<int> arr={2, 5, 1, 4, 3}; int target=10;
    // vector<int> arr={5, 7, 8}; int target=3;
    // vector<int> arr={35, 2, 8, 22}; int target=0;
    
    S.allDPWays(arr, target);
    cout<<S.perfectSum(arr, target)<<endl;
}
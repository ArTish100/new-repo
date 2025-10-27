//Matrix Chain Multiplication

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<climits>

using namespace std;

class Solution {
    public:
    
    void printVector(vector<int> vec){
        for(int a:vec)
            cout<<a<<" ";
        cout<<endl;
    }

    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=2;len<n;len++){
            for(int i=0;i<n-len;i++){
                int j=i+len;
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++){
                    int ans=dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j];
                    dp[i][j] = min(ans,dp[i][j]);
                }
            }
        }
        return dp[0][n-1];
    }

    int memoizWay(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int ans=memoizWay(arr,i,k,dp)+memoizWay(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            mini=min(ans,mini);
        }
        return dp[i][j]=mini;
    }

    int recurWay(vector<int>& arr, int i, int j){
        if(i==j)
            return 0;
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int ans=recurWay(arr,i,k)+recurWay(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            mini=min(ans,mini);
        }
        return mini;
    }

    void allDPWays(vector<int>& arr) {
        int n=arr.size();
        cout<<recurWay(arr, 1, n-1)<<endl;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        cout<<memoizWay(arr, 1, n-1, dp)<<endl;
        cout<<tabulation(arr)<<endl;
    }
    
};

int main(){
    vector<int> arr = {2, 1, 3, 4};
    // vector<int> arr = {2, 1, 3, 4};
    
    Solution S;
    S.allDPWays(arr);
}
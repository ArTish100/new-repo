//Max Sum Increasing Subsequence

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

    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int r1=INT_MIN;
                if(prev==-1 || arr[prev]<arr[ind])
                    r1=arr[ind]+dp[ind+1][ind+1];
                dp[ind][prev+1] = max(r1,dp[ind+1][prev+1]);
            }
        }
        for(int i=0;i<=n;i++)
            printVector(dp[i]);
        return dp[0][0];
    }

    int memoizWay(vector<int>& arr, int ind, int prev, vector<vector<int>>& dp, int n){
        if(ind==n)
            return 0;
        if(dp[prev+1][ind]!=-1)
            return dp[prev+1][ind];
        int r1=memoizWay(arr, ind+1, prev, dp, n);
        int r2=INT_MIN;
        if(prev==-1 || arr[prev]<arr[ind])
            r2=arr[ind]+memoizWay(arr,ind+1, ind, dp, n);
        return dp[prev+1][ind]=max(r1,r2);
    }

    int recurWay(vector<int>& arr, int ind, int prev, int &n){
        if(ind==n)
            return 0;
        // cout<<arr[ind]<<" "<<arr[prev]<<endl;
        int r1=recurWay(arr, ind+1, prev, n);
        int r2=INT_MIN;
        if(prev==-1 || arr[prev]<arr[ind])
            r2=arr[ind]+recurWay(arr, ind+1, ind, n);
        return max(r1,r2);
    }

    void allDPWays(vector<int>& arr) {
        int n=arr.size();
        cout<<recurWay(arr, 0, -1, n)<<endl;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        cout<<memoizWay(arr, 0, -1, dp, n)<<endl;
        cout<<tabulation(arr)<<endl;
    }
    
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            vector<int> curr(n+1,0);
            for(int prev=ind-1;prev>=-1;prev--){
                int r1=INT_MIN;
                if(prev==-1 || arr[prev]<arr[ind])
                    r1=arr[ind]+dp[ind+1];
                curr[prev+1] = max(r1,dp[prev+1]);
            }
            dp=curr;
        }
        return dp[0];
    }
};

int main(){
    vector<int> arr={1, 101, 2, 3, 100};
    // vector<int> arr={4, 1, 2, 3};
    // vector<int> arr={4, 1, 2, 4};
    // vector<int> arr={9, 4, 8, 2};
    
    Solution S;
    S.allDPWays(arr);
    cout<<S.maxSumIS(arr);
}
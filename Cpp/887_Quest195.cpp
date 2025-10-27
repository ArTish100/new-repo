//887. Super Egg Drop

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

    int tabulation(int k, int n){
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        int cnt=0;
        while(dp[cnt][k]<n){
            cnt++;
            for(int i=0;i<=k;i++){
                dp[cnt][i]=1+dp[cnt-1][i-1]+dp[cnt-1][i];
            }
        }
        return cnt;
    }

    int memoizWay(int k, int n, vector<vector<int>> &dp){
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int curr=1+max(memoizWay(k-1,i-1,dp),memoizWay(k,n-i,dp));
            ans = min(ans,curr);
        }
        return ans;
    }

    int recurWay(int k, int n){
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;
        
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int curr = 1+max(recurWay(k-1,i-1),recurWay(k,n-i));
            ans = min(ans,curr);
        }
        return ans;
    }

    void allDPWays(int k, int n) {
        cout<<recurWay(k,n)<<endl;
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        cout<<memoizWay(k,n,dp)<<endl;
        cout<<tabulation(k,n)<<endl;
    }
    
    int superEggDrop(int k, int n) {
        
    }
};

int main(){
    int k=1; int n=2;
    // int k=2; int n=6;
    // int k=3; int n=14;
    // int k=2; int n=10;
    
    
    Solution S;
    S.allDPWays(k, n);
    // cout<<S.superEggDrop(arr);
}
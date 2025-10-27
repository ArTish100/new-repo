//1547. Minimum Cost to Cut a Stick

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

    int tabulation(int n, vector<int>& cuts){
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int len=2;len<=m;len++){
            for(int i=0;i+len<m;i++){
                int j=len+i;
                int cost = cuts[j] - cuts[i];
                int mini = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    mini = min(mini, dp[i][k] + dp[k][j] + cost);
                }
                dp[i][j] = (mini == INT_MAX) ? 0 : mini;
            }
        }
        return dp[0][m-1];
        
    }

    int memoizWay(int n, vector<int>& cuts, int l, int r, vector<vector<int>>& dp){
        if(r-l==1)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int r1;
        int r2;
        int cost=r-l;
        int mini=INT_MAX;
        for(int i:cuts){
            if(l<i && i<r){
                mini=min(mini,memoizWay(n,cuts,l,i,dp)+memoizWay(n,cuts,i,r,dp));
            }
        }
        if(mini==INT_MAX)
            return dp[l][r]=0;
        return dp[l][r]=cost+mini;
    }

    int recurWay(int n, vector<int>& cuts, int l, int r){
        if(r-l==1)
            return 0;
        int r1;
        int r2;
        int cost=r-l;
        int mini=INT_MAX;
        for(int i:cuts){
            if(l<i && i<r){
                mini=min(mini,recurWay(n,cuts,l,i)+recurWay(n,cuts,i,r));
            }
        }
        if(mini==INT_MAX)
            return 0;
        return cost+mini;
    }

    void allDPWays(int n, vector<int>& cuts) {
        cout<<recurWay(n,cuts,0,n)<<endl;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        cout<<memoizWay(n,cuts,0,n,dp)<<endl;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
    }
};

int main(){
    int n=7 ; vector<int> cuts = {1,3,4,5};
    // int n=7 ; vector<int> cuts = {1};
    // int n=7 ; vector<int> cuts = {1};
    
    Solution S;
    S.allDPWays(n, cuts);
    // cout<<S.minCost(arr);
}
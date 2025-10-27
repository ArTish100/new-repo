// 0/1 Knapsack (DP - 19)

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

    int tabulation(int W, vector<int>& val, vector<int>& wt){
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        for(int ind=1;ind<=n;ind++){
            for(int w=0;w<=W;w++){
                int r1=0;
                if(w>=wt[ind-1])
                    r1=val[ind-1]+dp[ind-1][w-wt[ind-1]];
                int r2=dp[ind-1][w];
                dp[ind][w]=max(r1,r2);
            }
            // printVector(dp[ind]);
        }
        return dp[n][W];
    }

    int memoizWay(int W, vector<int>& val, vector<int>& wt, int ind, int n, vector<vector<int>>& dp){
        if(ind==n)
            return 0;
        if(dp[W][ind]!=-1)
            return dp[W][ind];    
        int r1=0;
        if(W>=wt[ind])
            r1=val[ind]+memoizWay(W-wt[ind], val, wt, ind+1, n, dp);
        int r2=memoizWay(W, val, wt, ind+1, n, dp);
        return dp[W][ind]=max(r1,r2);
    }

    int recurWay(int W, vector<int>& val, vector<int>& wt, int ind, int n){
        if(ind==n)
            return 0;
        int r1=0;
        if(W>=wt[ind])
            r1=val[ind]+recurWay(W-wt[ind], val, wt, ind+1, n);
        int r2=recurWay(W, val, wt, ind+1, n);
        return max(r1,r2);
    }

    void allDPWays(int W, vector<int>& val, vector<int>& wt) {
        int n=wt.size();
        cout<<recurWay(W, val, wt, 0, n)<<endl;
        vector<vector<int>> dp(W+1,vector<int>(n,-1));
        cout<<memoizWay(W, val, wt, 0, n, dp)<<endl;
        cout<<tabulation(W, val, wt)<<endl;
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<int> dp(W+1,0);
        for(int ind=1;ind<=n;ind++){
            vector<int> curr(W+1,0);
            for(int w=0;w<=W;w++){
                int r1=0;
                if(w>=wt[ind-1])
                    r1=val[ind-1]+dp[w-wt[ind-1]];
                int r2=dp[w];
                curr[w]=max(r1,r2);
            }
            dp=curr;
        }
        return dp[W];
        
    }
};

int main(){
    vector<int> val={1,2,3}; vector<int> wt={4,5,1}; int W=5;
    // vector<int> val={1,2,3}; vector<int> wt={4,5,6}; int W=3;
    // vector<int> val={10,40,30,50}; vector<int> wt={5,4,2,3}; int W=5;
    Solution S;
    S.allDPWays(W, val, wt);
    cout<<S.knapsack(W, val, wt);

}
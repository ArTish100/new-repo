//62. Unique Paths

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0)
                    dp[i][j]+=dp[i-1][j];
                if(j-1>=0)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int memoizWay(vector<vector<int>> &dp, int i, int j){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a=0, b=0;
        if(i-1>=0){
            dp[i-1][j] = memoizWay(dp,i-1,j);
            a = dp[i-1][j];
        }
        if(j-1>=0){
            dp[i][j-1] = memoizWay(dp,i,j-1);
            b = dp[i][j-1];
        }
        return a+b;
    }
    int recurWay(int i, int j){
        if(i<0 || j<0)
            return 0;
        if(i==0 && j==0)
            return 1;
        return recurWay(i-1,j)+recurWay(i,j-1);
    }
    void allDPWays(int m, int n) {
        // vector<vector<int>> vec(m,n);
        cout<<recurWay(m-1, n-1)<<endl;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        cout<<memoizWay(dp,m-1, n-1)<<endl;
        cout<<tabulation(m, n)<<endl;
    }
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        int up, left;
        for(int i=0;i<m;i++){
            vector<int> vec(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    vec[0] = 1;
                    continue;
                }
                up=0;
                left=0;
                if(i>0)
                    up = dp[j];
                if(j>0)
                    left = vec[j-1];
                vec[j] = up+left;
                
            }
            dp = vec;
        }
        return dp[n-1];
    }
};

int main(){
    Solution S;
    // vector<vector<int>> vec = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    // vector<vector<int>> vec = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    // vector<vector<int>> vec = {{4,2,6}};
    S.allDPWays(3,7);
    cout<<S.uniquePaths(3,7)<<endl;
}
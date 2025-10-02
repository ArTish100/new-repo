//63. Unique Paths II

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1)
            return 0;
        int a=0,b=0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[0][0] = 1;
                    continue;
                }
                a=0;
                b=0;
                if(i-1>=0)
                    a=dp[i-1][j];
                if(j-1>=0)
                    b=dp[i][j-1];
                dp[i][j]=a+b;
            }
        }
        return dp[m-1][n-1];
    }
    int memoizWay(vector<vector<int>> &vec, vector<vector<int>> &dp, int i, int j){
        if(vec[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0 && j==0)
            return 1;
        int a=0;
        int b=0;
        if(i-1>=0)
            a = memoizWay(vec,dp,i-1,j);
        if(j-1>=0)
            b = memoizWay(vec,dp,i,j-1);
        return dp[i][j] = a+b;
    }
    int recurWay(vector<vector<int>> &vec, int i, int j){
        if(i<0 || j<0)
            return 0;
        if(vec[i][j]==1)
            return 0;
        if(i==0 && j==0)
            return 1;
        return recurWay(vec,i-1,j)+recurWay(vec,i,j-1);
    }
    void allDPWays(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        cout<<recurWay(obstacleGrid, m-1, n-1)<<endl;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        cout<<memoizWay(obstacleGrid, dp, m-1, n-1)<<endl;
        cout<<tabulation(obstacleGrid)<<endl;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n,0);
        int a,b;
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    curr[j] = 0;
                    continue;
                }
                if(i==0 && j==0){
                    curr[0] = 1;
                    continue;
                }
                a=0;
                b=0;
                if(i-1>=0)
                    a=dp[j];
                if(j-1>=0)
                    b=curr[j-1];
                curr[j]=a+b;
            }
            dp = curr;
        }
        return dp[n-1];
    }
};

int main(){
    Solution S;
    // vector<vector<int>> vec = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    // vector<vector<int>> vec = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    // vector<vector<int>> vec = {{4,2,6}};
    // vector<vector<int>> obstacleGrid={{0,1},{0,0}};
    vector<vector<int>> obstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
    S.allDPWays(obstacleGrid);
    cout<<S.uniquePathsWithObstacles(obstacleGrid)<<endl;
}
//64. Minimum Path Sum

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<vector<int>>& grid) {
        int a;
        int b;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[0][0]=grid[0][0];
                    continue;
                }
                a=INT_MAX;
                b=INT_MAX;
                if(i-1>=0)
                    a=dp[i-1][j];
                if(j-1>=0)
                    b=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(a,b);
            }
        }
        return dp[m-1][n-1];
    }
    int memoizWay(vector<vector<int>> &vec, vector<vector<int>> &dp, int i, int j) {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0 && j==0)
            return vec[0][0];
        int a=INT_MAX;
        int b=INT_MAX;
        if(i-1>=0)
            a=memoizWay(vec,dp,i-1,j);
        if(j-1>=0)
            b=memoizWay(vec,dp,i,j-1);
        return vec[i][j]+min(a,b);
    }
    int recurWay(vector<vector<int>> &vec, int i, int j) {
        if(i==0 && j==0)
            return vec[i][j];
        int a=INT_MAX;
        int b=INT_MAX;
        if(i-1>=0)
            a=recurWay(vec,i-1,j);
        if(j-1>=0)
            b=recurWay(vec,i,j-1);
        return vec[i][j]+min(a,b);
    }
    void allDPWays(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        cout<<recurWay(obstacleGrid,m-1,n-1)<<endl;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        cout<<memoizWay(obstacleGrid, dp, m-1, n-1)<<endl;
        cout<<tabulation(obstacleGrid)<<endl;
    }
    int minPathSum(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int a,b;
        vector<int> dp(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[0]=grid[0][0];
                    continue;
                }
                a=INT_MAX;
                b=INT_MAX;
                if(i-1>=0)
                    a=dp[j];
                if(j-1>=0)
                    b=curr[j-1];
                curr[j] = grid[i][j]+min(a,b);
            }
            dp=curr;
        }
        return dp[n-1];
    }
};

int main(){
    Solution S;
    vector<vector<int>> obstacleGrid={{1,3,1},{1,5,1},{4,2,1}};
    // vector<vector<int>> obstacleGrid={{1,2,3},{4,5,6}};
    S.allDPWays(obstacleGrid);
    cout<<S.minPathSum(obstacleGrid)<<endl;
}
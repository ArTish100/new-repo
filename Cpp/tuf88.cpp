//64. Minimum Path Sum

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

    int tabulation(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[0][0]=grid[0][0];
                    continue;
                }
                int r1=INT_MAX;
                if(i-1>=0)
                    r1=dp[i-1][j];
                int r2=INT_MAX;
                if(j-1>=0)
                    r2=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(r1,r2);
            }       
        }
        return dp[m-1][n-1];
    }

    int memoizWay(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0)
            return dp[0][0]=grid[0][0];
        if(i<0 || j<0)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int r1=memoizWay(grid, i-1, j, dp);
        int r2=memoizWay(grid, i, j-1, dp);
        return dp[i][j]=grid[i][j]+min(r1,r2);
    }

    int recurWay(vector<vector<int>>& grid, int i, int j){
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0 || j<0)
            return INT_MAX;
        int r1=recurWay(grid, i-1, j);
        int r2=recurWay(grid, i, j-1);
        return grid[i][j]+min(r1,r2);
    }

    void allDPWays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        cout<<recurWay(grid, m-1, n-1)<<endl;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        cout<<memoizWay(grid, m-1, n-1, dp)<<endl;
        cout<<tabulation(grid)<<endl;
    }
    
    int minPathSum(vector<vector<int>> &grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(m,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[0]=grid[0][0];
                    continue;
                }
                int r1=INT_MAX;
                if(i-1>=0)
                    r1=dp[j];
                int r2=INT_MAX;
                if(j-1>=0)
                    r2=curr[j-1];
                curr[j]=grid[i][j]+min(r1,r2);
            }       
            dp=curr;
        }
        return dp[n-1];
    }
};

int main(){
    vector<vector<int>> arr={{1,3,1},{1,5,1},{4,2,1}};
    // vector<vector<int>> arr={{1, 2, 3},{4,5,6}};
    
    Solution S;
    S.allDPWays(arr);
    cout<<S.minPathSum(arr);
}
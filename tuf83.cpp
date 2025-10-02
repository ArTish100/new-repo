//Ninja and his friends

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    
    int tabulation(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        int maxi;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)
                    dp[n-1][i][j] = grid[n-1][i];
                else
                    dp[n-1][i][j] = grid[n-1][i]+grid[n-1][j];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int curr1=0;curr1<m;curr1++){
                for(int curr2=0;curr2<m;curr2++){
                    maxi=INT_MIN;
                    for(int j=-1;j<=1;j++){
                        for(int k=-1;k<=1;k++){
                            if(curr1+j>=0 && curr2+k>=0 && curr1+j<m && curr2+k<m)
                                maxi = max(maxi,dp[i+1][curr1+j][curr2+k]);
                        }
                    }
                    if(curr1==curr2){
                        dp[i][curr1][curr2] = grid[i][curr1] + maxi;
                    }else{
                        dp[i][curr1][curr2] = grid[i][curr1] + grid[i][curr2] + maxi;
                    }
                }
            }
        }
        
        return dp[0][0][m-1];
    }
    
    int memoizWay(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int n, int m, int curr1, int curr2, int curow) {
        // cout<<curr1<<" "<<curr2<<" "<<curow<<endl;
        if(curr1<0 || curr2<0 || curr1>=m || curr2>=m)
            return 0;
        if(curow==n-1){
            if(curr1==curr2)
                return dp[n-1][curr1][curr2]=grid[n-1][curr1];
            return dp[n-1][curr1][curr2]=grid[n-1][curr1] + grid[n-1][curr2];
        }
        if(dp[curow][curr1][curr2]!=-1)
            return dp[curow][curr1][curr2];
        int maxi=INT_MIN;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                maxi=max(maxi,memoizWay(grid, dp, n, m, curr1+i, curr2+j, curow+1));
            }
        }
        if(curr1==curr2)
            return dp[curow][curr1][curr2] = grid[curow][curr1]+maxi;
        return dp[curow][curr1][curr2] = grid[curow][curr1]+grid[curow][curr2]+maxi;
    }
    int recurWay(vector<vector<int>> &grid, int n, int m, int curr1, int curr2, int curow) {
        if(curr1>=m || curr2>=m || curr1<0 || curr2<0)
            return 0;
        if(curow==n-1){
            if(curr1==curr2)
                return grid[n-1][curr1];
            return grid[n-1][curr1]+grid[n-1][curr2];
        }
        int maxi=INT_MIN;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                maxi=max(maxi,recurWay(grid, n, m, curr1+i, curr2+j, curow+1));
            }
        }
        if(curr1==curr2)
            return grid[curow][curr1]+maxi;
        return grid[curow][curr1]+grid[curow][curr2]+maxi;
    }
    void allDPWays(int n, int m, vector<vector<int>>& grid) {
        cout<<recurWay(grid, n, m, 0, m-1, 0)<<endl;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        cout<<memoizWay(grid, dp, n, m, 0, m-1, 0)<<endl;
        cout<<tabulation(n, m, grid)<<endl;
        // cout<<tabulationWay(grid)<<endl;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dp(m,vector<int>(m,0));
        int maxi;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)
                    dp[i][j] = grid[n-1][i];
                else
                    dp[i][j] = grid[n-1][i]+grid[n-1][j];
            }
        }
        for(int i=n-2;i>=0;i--){
            vector<vector<int>> curr(m,vector<int>(m,0));
            for(int curr1=0;curr1<m;curr1++){
                for(int curr2=0;curr2<m;curr2++){
                    maxi=INT_MIN;
                    for(int j=-1;j<=1;j++){
                        for(int k=-1;k<=1;k++){
                            if(curr1+j>=0 && curr2+k>=0 && curr1+j<m && curr2+k<m)
                                maxi = max(maxi,dp[curr1+j][curr2+k]);
                        }
                    }
                    if(curr1==curr2){
                        curr[curr1][curr2] = grid[i][curr1] + maxi;
                    }else{
                        curr[curr1][curr2] = grid[i][curr1] + grid[i][curr2] + maxi;
                    }
                }
            }
            dp = curr;
        }
        
        return dp[0][m-1];
    }
};

int main(){
    Solution S;
    // vector<vector<int>> grid={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    // vector<vector<int>> grid={{4,1,2},{3,6,1},{1,6,6},{3,1,2}};
    vector<vector<int>> grid= {{2, 0, 0, 0, 0, 0, 2}, {2, 1, 0, 0, 0, 4, 0}, {2, 0, 10, 0, 1, 0, 0}, {0, 3, 0, 6, 5, 0, 0}, {1, 0, 3, 4, 0, 0, 6}};
    int n=grid.size();
    int m=grid[0].size();
    S.allDPWays(n, m, grid);
    cout<<S.solve(n, m, grid)<<endl;
}
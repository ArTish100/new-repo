//120. Triangle

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        int a;
        int b;
        int ind=0;
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                a = triangle[i][j] + dp[i+1][j];
                b = triangle[i][j] + dp[i+1][j+1];
                dp[i][j]=min(a,b);
            }
        }
        return dp[0][0];
    }
    int memoizWay(vector<vector<int>> &triangle, vector<vector<int>> &dp, int m, int curr) {
        if(dp[curr][m]!=-1)
            return dp[curr][m];
        if(curr==0)
            return triangle[0][0];
        if((m>curr) || (m-1>=0 && triangle[curr][m-1]<triangle[curr][m])){
            return dp[curr][m-1]=triangle[curr][m-1]+memoizWay(triangle,dp,m-1,curr-1);
        }else{
            return dp[curr][m]=triangle[curr][m]+memoizWay(triangle,dp,m,curr-1);
        }
    }
    int recurWay(vector<vector<int>> &triangle, int m, int curr) {
        if(curr==0)
            return triangle[0][0];
        if((m>curr) || (m-1>=0 && triangle[curr][m-1]<triangle[curr][m]))
            return triangle[curr][m-1]+recurWay(triangle, m-1, curr-1);
        else
            return triangle[curr][m]+recurWay(triangle, m, curr-1);
    }
    void allDPWays(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int mini=INT_MAX;
        int ind;
        for(int i=0;i<m;i++){
            if(triangle[m-1][i]<mini){
                mini=triangle[m-1][i];
                ind=i;
            }
        }
        // cout<<mini<<endl;
        cout<<recurWay(triangle,ind,m-1)<<endl;
        vector<vector<int>> dp(m,vector<int>(m,-1));
        cout<<memoizWay(triangle,dp,ind,m-1)<<endl;
        cout<<tabulation(triangle)<<endl;
    }
    int minimumTotal(vector<vector<int>>& triangle){
        int m=triangle.size();
        vector<int> dp(m,0);
        for(int i=0;i<m;i++){
            dp[i] = triangle[m-1][i];
        }
        int a;
        int b;
        vector<int> curr(m,0);
        for(int i=m-2;i>=0;i--){
            
            for(int j=i;j>=0;j--){
                a = triangle[i][j] + dp[j];
                b = triangle[i][j] + dp[j+1];
                curr[j]=min(a,b);
            }
            dp = curr;
        }
        return dp[0];
    }
};

int main(){
    Solution S;
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    // vector<vector<int>> triangle={{-10},{-2,-6}};
    S.allDPWays(triangle);
    cout<<S.minimumTotal(triangle)<<endl;
}
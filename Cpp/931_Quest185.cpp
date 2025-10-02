//931. Minimum Falling Path Sum

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        dp[m-1] = matrix[m-1];
        int up,left,right;
        for(int i=m-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                up=INT_MAX;
                left=INT_MAX;
                right=INT_MAX;
                up=dp[i+1][j];
                if(j-1>=0)
                    left=dp[i+1][j-1];
                if(j+1<m)
                    right=dp[i+1][j+1];
                dp[i][j]=matrix[i][j] + min({up,left,right});
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,dp[0][i]);
        }
        return mini;
    }
    int memoizWay(vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int curr, int mlen) {
        if(curr<0 || curr>=mlen)
            return INT_MAX;
        if(m==0)
            return matrix[0][curr];
        if(dp[m][curr]!=-1)
            return dp[m][curr];
        int up,left,right;
        up=memoizWay(matrix, dp, m-1, curr, mlen);
        left=memoizWay(matrix, dp, m-1, curr-1, mlen);
        right=memoizWay(matrix, dp, m-1, curr+1, mlen);
        return dp[m][curr]=matrix[m][curr]+min({up,left,right});
    }
    int recurWay(vector<vector<int>> &matrix, int m, int curr, int mlen) {
        if(curr<0 || curr>=mlen)
            return INT_MAX;
        if(m==0)
            return matrix[0][curr];
        int up,left,right;
        up=recurWay(matrix, m-1, curr, mlen);
        left=recurWay(matrix, m-1, curr-1, mlen);
        right=recurWay(matrix, m-1, curr+1, mlen);
        return matrix[m][curr] + min({up,left,right});
    }
    void allDPWays(vector<vector<int>>& matrix) {
        int mlen = matrix.size();
        int mini=INT_MAX;
        for(int i=0;i<mlen;i++){
            mini=min(mini,recurWay(matrix, mlen-1, i, mlen));
        }
        cout<<mini<<endl;
        mini=INT_MAX;
        vector<vector<int>> dp(mlen,vector<int>(mlen,-1));
        for(int i=0;i<mlen;i++){
            mini=min(mini,memoizWay(matrix, dp, mlen-1, i, mlen));
        }
        cout<<mini<<endl;
        cout<<tabulation(matrix)<<endl;
    }
    int minFallingPathSum(vector<vector<int>>& matrix){
        int m=matrix.size();
        vector<int> dp(m,-1);
        dp = matrix[m-1];
        int up,left,right;
        for(int i=m-2;i>=0;i--){
            vector<int> curr(m,-1);
            for(int j=m-1;j>=0;j--){
                up=INT_MAX;
                left=INT_MAX;
                right=INT_MAX;
                up=dp[j];
                if(j-1>=0)
                    left=dp[j-1];
                if(j+1<m)
                    right=dp[j+1];
                curr[j]=matrix[i][j] + min({up,left,right});
            }
            dp=curr;
        }
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,dp[i]);
        }
        return mini;
    }
};

int main(){
    Solution S;
    vector<vector<int>> matrix={{2,1,3},{6,5,4},{7,8,9}};
    // vector<vector<int>> matrix={{-19,57},{-40,-5}};
    // vector<vector<int>> matrix={{-19}};
    S.allDPWays(matrix);
    cout<<S.minFallingPathSum(matrix)<<endl;
}
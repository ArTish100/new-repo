//Ninja's Training or Geek's Training

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<vector<int>> &nums){
        int nlen = nums.size();
        int maxi = 0;
        vector<vector<int>> dp(nlen, vector<int>(3,-1));
        for(int i=0;i<3;i++){
            dp[0][i] = nums[0][i];
        }
        for(int i=1;i<nlen;i++){
            maxi = 0;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(k!=j)
                        maxi = max(dp[i-1][k] + nums[i][j],maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return max({dp[nlen-1][0],dp[nlen-1][1],dp[nlen-1][2]});
    }
    int memoizWay(vector<vector<int>> &vec, vector<vector<int>> &dp, int ind, int last){
        if(dp[ind][last]!=-1)
            return dp[ind][last];
        int maxi = 0;
        if(ind==0){
            for(int i=0;i<3;i++){
                if(last!=i)
                    maxi = max(maxi, vec[0][i]);
            }
            return dp[0][last] = maxi;
        }
        maxi = 0;
        for(int i=0;i<3;i++){
            if(last!=i)
                maxi = max(maxi, vec[ind][i]+memoizWay(vec, dp, ind-1, i));
        }
        return dp[ind][last] = maxi;
    }
    int recurWay(vector<vector<int>> &vec, int ind, int last){
        int maxi = 0;
        if(ind==0){
            for(int i=0;i<3;i++){
                if(i!=last)
                    maxi = max(maxi, vec[ind][i]);
            }
            return maxi;
        }
        maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi = max(maxi, vec[ind][i] + recurWay(vec, ind-1, i));
        }
        return maxi;
    }
    void allWaysMaximumPoints(vector<vector<int>>& arr) {
        int alen = arr.size();
        cout<<recurWay(arr, alen-1, 0)<<endl;
        vector<vector<int>> dp(alen, vector<int>(3, -1));
        cout<<memoizWay(arr, dp, alen-1, 0)<<endl;
        for(auto a : dp){
            for(auto b : a){
                cout<<b<<" ";
            }    
            cout<<endl;
        }
        cout<<tabulation(arr)<<endl;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int alen = arr.size();
        vector<int> dp = arr[0];
        int maxi;
        for(int i=1;i<alen;i++){
            vector<int> curr(3);
            for(int j=0;j<3;j++){
                maxi = 0;
                for(int k=0;k<3;k++){
                    if(k!=j)
                        maxi = max(maxi, dp[k]);
                }
                curr[j] = maxi + arr[i][j];
            }
            dp = curr;
        }
        return max({dp[0],dp[1],dp[2]});
    }
    int maxMeritOptimized(const vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        vector<int> prev = {arr[0][0], arr[0][1], arr[0][2]};
        for (int i = 1; i < n; ++i) {
            vector<int> cur(3);
            for (int k = 0; k < 3; ++k) {
                int bestPrev = 0;
                for (int m = 0; m < 3; ++m) {
                    if (m == k) continue;
                    bestPrev = max(bestPrev, prev[m]);
                }
                cur[k] = arr[i][k] + bestPrev;
            }
            prev = cur;
        }
        return max({prev[0], prev[1], prev[2]});
    }
};

int main(){
    Solution S;
    vector<vector<int>> vec = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    // vector<vector<int>> vec = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    // vector<vector<int>> vec = {{4,2,6}};
    S.allWaysMaximumPoints(vec);
    cout<<S.maximumPoints(vec)<<endl;
    cout<<S.maxMeritOptimized(vec)<<endl;
}



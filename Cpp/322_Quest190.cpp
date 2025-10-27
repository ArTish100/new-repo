//322. Coin Change

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

    int tabulation(vector<int>& coins, int amount){
        int n=coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(int c:coins){
                if(i-c>=0){
                    dp[i] = min(dp[i],1+dp[i-c]);
                }
            }
        }
        return dp[amount]!=amount+1 ? dp[amount] : -1;
    }

    int memoizWay(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0)
            return 0;
        if(amount<0)
            return INT_MAX/2;
        if(dp[amount]!=-1)
            return dp[amount];
        int best=INT_MAX/2;
        for(int i:coins){
            int mini = memoizWay(coins, amount-i,dp);
            if(mini<INT_MAX/2)
                best=min(1+mini,best);
        }
        return dp[amount]=best;
    }

    int recurWay(vector<int>& coins, int amount){
        if(amount==0)
            return 0;
        if(amount<0)
            return INT_MAX/2;
        int best=INT_MAX/2;
        for(int i:coins){
            int mini = recurWay(coins, amount-i);
            if(mini<INT_MAX/2)
                best=min(1+mini,best);
        }
        return best;
    }

    void allDPWays(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans = recurWay(coins, amount);
        if(ans==INT_MAX/2)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
        
        vector<int> dp(amount+1,-1);
        ans = memoizWay(coins, amount, dp);
        if(ans==INT_MAX/2)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
        cout<<tabulation(coins, amount)<<endl;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
    }
};

int main(){
    // vector<int> coins = {1,2,5}; int amount = 11;

    // vector<int> coins = {2}; int amount = 3;

    vector<int> coins = {1}; int amount = 0;
    
    Solution S;
    S.allDPWays(coins, amount);
    // cout<<S.coinChange(arr);
}
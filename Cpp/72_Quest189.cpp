//72. Edit Distance

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

    int tabulation(string word1, string word2){
        int wlen1=word1.length();
        int wlen2=word2.length();
        vector<vector<int>> dp(wlen1+1, vector<int>(wlen2+1,0));
        for(int i=0;i<=wlen1;i++)
            dp[i][0]=i;
        for(int j=0;j<=wlen2;j++)
            dp[0][j]=j;
        for(int i=1;i<=wlen1;i++){
            for(int j=1;j<=wlen2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[wlen1][wlen2];
    }

    int memoizWay(string word1, string word2, int ind1, int ind2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0){  
            return 1;
        }
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2]){
            // eqwrd[ind2]=word2[ind2];
            return dp[ind1][ind2]=memoizWay(word1, word2, ind1-1, ind2-1, dp);
        }else{
            int r1 = memoizWay(word1, word2, ind1, ind2-1, dp);
            int r2 = memoizWay(word1, word2, ind1-1, ind2, dp);
            int r3 = memoizWay(word1, word2, ind1-1, ind2-1, dp);
            // cout<<r1<<" "<<r2<<" "<<r3<<endl;
            return dp[ind1][ind2]=1+min({r1,r2,r3});
        }
    }

    int recurWay(string word1, string word2, int ind1, int ind2){
        if(ind1<0 || ind2<0){  
            return 1;
        }
        if(word1[ind1]==word2[ind2]){
            // eqwrd[ind2]=word2[ind2];
            return recurWay(word1, word2, ind1-1, ind2-1);
        }else{
            int r1 = recurWay(word1, word2, ind1, ind2-1);
            int r2 = recurWay(word1, word2, ind1-1, ind2);
            int r3 = recurWay(word1, word2, ind1-1, ind2-1);
            // cout<<r1<<" "<<r2<<" "<<r3<<endl;
            return 1+min({r1,r2,r3});
        }
    }

    void allDPWays(string word1, string word2) {
        int wlen1=word1.length();
        int wlen2=word2.length();
        cout<<recurWay(word1, word2, wlen1-1, wlen2-1)<<endl;
        vector<vector<int>> dp(wlen1, vector<int>(wlen2,-1));
        cout<<memoizWay(word1, word2, wlen1-1, wlen2-1, dp)<<endl;
        cout<<tabulation(word1, word2)<<endl;
    }
    
    int minDistance(string word1, string word2) {
        int wlen1=word1.length();
        int wlen2=word2.length();
        vector<int> dp(wlen2+1,0);
        for(int i=0;i<=wlen2;i++)
            dp[i]=i;
        for(int i=1;i<=wlen1;i++){
            vector<int> curr(wlen2+1,0);
            for(int j=1;j<=wlen2;j++){
                curr[0]=j;
                if(word1[i-1]==word2[j-1]){
                    curr[j]=dp[j-1];
                }else{
                    curr[j]=1+min({dp[j],curr[j-1],dp[j-1]});
                }
            }
            dp=curr;
        }
        return dp[wlen2];
    }
};

int main(){
    string word1 = "horse"; string word2 = "ros";
    // string word1 = "intention"; string word2 = "execution";
    Solution S;
    S.allDPWays(word1, word2);
    cout<<S.minDistance(word1, word2);

}
//1143. Longest Common Subsequence

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<climits>

using namespace std;

class Solution {
    public:
    
    void printVector(vector<char> vector){
        for(char a:vector)
            cout<<a<<" ";
        cout<<endl;
    }

    int tabulation(string text1, string text2){
        int t1=text1.length();
        int t2=text2.length();
        vector<vector<int>> dp(t1,vector<int>(t2,0));
        dp[0][0]=text1[0]==text2[0];
        // vector<char> vec;
        for(int i=t1-1;i>=0;i--){
            for(int j=t2-1;j>=0;j--){
                int ans;
                if(text1[i]==text2[j]){
                    if(i+1<t1 && j+1<t2)
                        ans=1+dp[i+1][j+1]; 
                    else
                        ans=1;
                    // vec.push_back(text1[i]);
                }else{
                    int r1=0;
                    int r2=0;
                    if(j+1<t2)
                        r1=dp[i][j+1];
                    if(i+1<t1)
                        r2=dp[i+1][j];
                    ans=max(r1,r2);
                }
                // cout<<ans<<" "<<i<<" "<<j<<endl;
                dp[i][j]=ans;
            }
        }
        // printVector(vec);
        return dp[0][0];
    }

    int memoizWay(string text1, string text2, int t1, int t2, int i, int j, vector<vector<int>>& dp){
        if(i==t1 || j==t2)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j])
            return dp[i][j]=1+memoizWay(text1,text2,t1,t2,i+1,j+1,dp);
        else{
            return dp[i][j]=max(memoizWay(text1,text2,t1,t2,i+1,j,dp),memoizWay(text1,text2,t1,t2,i,j+1,dp));
        }
    }

    int recurWay(string text1, string text2, int t1, int t2, int i, int j){
        if(i==t1 || j==t2)
            return 0;
        int r1=recurWay(text1,text2,t1,t2,i+1,j);
        int r2=max(r1,recurWay(text1,text2,t1,t2,i,j+1));
        int r3=0;
        if(text1[i]==text2[j])
            r3=1+recurWay(text1,text2,t1,t2,i+1,j+1);
        return max(r2,r3);
        
    }

    void allDPWays(string text1, string text2) {
        int t1=text1.length();
        int t2=text2.length();
        cout<<recurWay(text1, text2, t1, t2, 0, 0)<<endl;
        vector<vector<int>> dp(t1,vector<int>(t2,-1));
        cout<<memoizWay(text1, text2, t1, t2, 0, 0, dp)<<endl;
        cout<<tabulation(text1,text2)<<endl;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.length();
        int t2=text2.length();
        vector<int> dp(t2,0);
        for(int i=t1-1;i>=0;i--){
            vector<int> curr(t2,0);
            for(int j=t2-1;j>=0;j--){
                int ans;
                if(text1[i]==text2[j]){
                    if(i+1<t1 && j+1<t2)
                        ans=1+dp[j+1]; 
                    else
                        ans=1;
                }else{
                    int r1=0;
                    int r2=0;
                    if(j+1<t2)
                        r1=curr[j+1];
                    if(i+1<t1)
                        r2=dp[j];
                    ans=max(r1,r2);
                }
                curr[j]=ans;
            }
            dp=curr;
        }
        return dp[0];
    }
};

int main(){
    // string text1 = "abcde"; string text2 = "ace" ;
    // string text1 = "abc"; string text2 = "abc";
    string text1 = "abc"; string text2 = "def";
    Solution S;
    S.allDPWays(text1, text2);
    cout<<S.longestCommonSubsequence(text1, text2);

}
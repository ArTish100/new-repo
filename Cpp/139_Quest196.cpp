//139. Word Break

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

    int tabulation(string s, vector<string>& wordDict){
        
    }

    int memoizWay(string s, unordered_set<string>& wordDict, int ind, int n, vector<int> &dp){
        if(ind==n)
            return true;
        if(dp[ind]!=-1)
            return dp[ind];
        string temp="";
        for(int i=ind;i<n;i++){
            temp+=s[i];
            if(wordDict.find(temp)!=wordDict.end() && memoizWay(s, wordDict, i+1, n, dp))
                return dp[ind]=true;
        }
        return dp[ind]=false;
    }

    int recurWay(string s, unordered_set<string>& wordDict, int ind, int n){
        if(ind==n)
            return true;
        string temp="";
        for(int i=ind;i<n;i++){
            temp+=s[i];
            if(wordDict.find(temp)!=wordDict.end() && recurWay(s, wordDict, i+1, n))
                return true;
        }
        return false;

    }

    void allDPWays(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> uset(wordDict.begin(),wordDict.end());
        cout<<recurWay(s, uset, 0, n)<<endl;
        vector<int> dp(n+1,-1);
        cout<<memoizWay(s, uset, 0, n, dp)<<endl;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
    }
};

int main(){
    // string s="leetcode"; vector<string> wordDict={"leet","code"};
    // string s="applepenapple"; vector<string> wordDict={"apple","pen"};
    string s="catsandog"; vector<string> wordDict={"cats","dog","sand","and","cat"};
    
    Solution S;
    S.allDPWays(s, wordDict);
    // cout<<S.wordBreak(arr);
}
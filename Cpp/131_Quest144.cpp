//131. Palindrome Partitioning

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printVec(vector<vector<string>> vec){
        for(auto a : vec){
            for(string b : a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
    }
    void printVecLin(vector<string> vec){
        for(auto b : vec){
                cout<<b<<" ";
        }
        cout<<endl;
    }
    bool isPalindrome(string s, int ind, int i){
        while(ind<=i){
            if(s[ind++]!=s[i--])
                return false;
        }
        
        return true;
    }
    void dfsFunction(vector<vector<string>> &ans,vector<string> dstr, string s, int ind){
        if(ind==s.length()){
            ans.push_back(dstr);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                dstr.push_back(s.substr(ind,i-ind+1));
                dfsFunction(ans, dstr, s, i+1);
                dstr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> dstr;
        dfsFunction(ans, dstr, s, 0);
        return ans;
    }
};

int main(){
    Solution S;
    string s = "aab";
    vector<vector<string>> ans = S.partition(s);
    S.printVec(ans);
}
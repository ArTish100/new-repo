//22. Generate Parentheses

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void genParen(vector<string> &ans,string &current,int n,int startbrack, int endbrack){
        if(startbrack == endbrack && startbrack == n){
            ans.push_back(current);
            return;
        }
        if(startbrack<n){
            current.push_back('(');
            genParen(ans,current,n,startbrack+1,endbrack);
            current.pop_back();
        }
        if(endbrack<startbrack){
            current.push_back(')');
            genParen(ans,current,n,startbrack,endbrack+1);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        genParen(ans,current,n,0,0);
        return ans;
    }
    void printVec(vector<string> vec){
        for(string a : vec){
            cout<<a<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Solution S;
    vector<string> ans = S.generateParenthesis(3);
    S.printVec(ans);
}
//37. Sudoku Solver

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printVec(vector<vector<char>> vec){
        for(auto b : vec){
            for(char a : b)
                cout<<a<<' ';
            cout<<endl;
        }
    }
    void printVecLin(vector<string> vec){
        for(auto b : vec){
                cout<<b<<' ';
        }
        cout<<endl;
    }
    void dfs(vector<string> &ans, const string &dstr, string &num, int &target, int ind, int nlen, int resdstr, int prevVal){
        if(ind == nlen){
            cout<<resdstr<<" "<<dstr<<endl;
            if(resdstr == target)
                ans.push_back(dstr);
            return;
        }
        int val = 0;
        string numstr="";
        for(int i=ind;i<nlen;i++){
            if(i>ind && num[ind]=='0')
                break;
            numstr+=num[i];
            val = (val*10)+(num[i]-'0');
            if(ind==0){
                dfs(ans, dstr+numstr, num, target, i+1, nlen, val, val);
            }else{
                dfs(ans, dstr+"+"+numstr, num, target, i+1, nlen, resdstr+val, val);
                dfs(ans, dstr+"-"+numstr, num, target, i+1, nlen, resdstr-val, -val);
                dfs(ans, dstr+"*"+numstr, num, target, i+1, nlen, resdstr-prevVal+prevVal*val, prevVal*val);
            }
        }
        return;
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string dstr="";
        int nlen = num.length();
        dfs(ans, dstr, num, target, 0, nlen, 0, 0);
        return ans;
    }
};

int main(){
    Solution S;
    string num = "105";
    int target = 5;
    vector<string> ans;
    // char c = num.back();
    // cout<<c-'0';
    ans = S.addOperators(num, target);
    S.printVecLin(ans);
}
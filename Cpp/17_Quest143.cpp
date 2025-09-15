//17. Letter Combinations of a Phone Number

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char,string> phonemap;
    Solution(){
        phonemap['2'] = "abc";
        phonemap['3'] = "def";
        phonemap['4'] = "ghi";
        phonemap['5'] = "jkl";
        phonemap['6'] = "mno";
        phonemap['7'] = "pqrs";
        phonemap['8'] = "tuv";
        phonemap['9'] = "wxyz";
    }
    
    void printVec(vector<vector<int>> vec){
        for(auto a : vec){
            for(int b : a){
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
    void dfs(vector<string> &ans, vector<string> &vec, int ind, string dstr){
        if(ind>=vec.size()){
            if(dstr.length()==vec.size()){
                ans.push_back(dstr);
            }
            return;
        }
        for(int j=0;j<vec[ind].length();j++){
            dstr.push_back(vec[ind][j]);
            dfs(ans,vec,ind+1,dstr);
            dstr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        vector<string> ans;
        vector<string> vec;
        string dstr;
        for(char a : digits){
            vec.push_back(phonemap[a]);
        }
        dfs(ans,vec,0,dstr);
        return ans;
    }
};

int main(){
    Solution S;
    string s = "237";
    vector<string> ans = S.letterCombinations(s);
    S.printVecLin(ans);
}
//Generate Binary Strings Without Consecutive 1s

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void dfs(int n, string &current, vector<string> &result) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        // Add '0'
        current.push_back('0');
        dfs(n, current, result);
        current.pop_back(); // backtrack

        // Add '1' only if last character is not '1'
        if (current.empty() || current.back() != '1') {
            current.push_back('1');
            dfs(n, current, result);
            current.pop_back(); // backtrack
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> result;
        string current;
        dfs(n, current, result);
        return result;
    }

    void genBinStr(int n, vector<string> &vec){
        if(n==1){
            vec.push_back("0");
            vec.push_back("1");
            return;
        }
        genBinStr(n-1, vec);
        vector<string> addvec;
        for(string &a : vec){
            addvec.push_back(a+"0");
            if(a.back()!='1'){
                addvec.push_back(a+"1");
            }
        }
        vec.clear();
        for(string b : addvec){
            vec.push_back(b);
        }
        return;
    }
    vector<string> generateBinaryStrings1(int n) {
        vector<string> vec;
        genBinStr(n,vec);
        return vec;
    }
    void printVec(vector<string> vec){
        for(string a : vec){
            cout<<a<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Solution S;
    vector<string> vec = S.generateBinaryStrings(5);
    S.printVec(vec);
}
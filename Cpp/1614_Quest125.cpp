//1614. Maximum Nesting Depth of the Parentheses

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int slen = s.length();
        int cnt = 0;
        int maxans = 0;
        for(int i=0;i<slen;i++){
            if(s[i]=='('){
                cnt++;
                maxans = max(cnt,maxans);
            }else if(s[i]==')'){
                cnt--;
            }
        }
        return maxans;
    }
};

int main(){
    Solution S;
    string s1 = "()(())(())";
    cout<<S.maxDepth(s1);
}
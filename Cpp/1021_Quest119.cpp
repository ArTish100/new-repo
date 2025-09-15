//1021. Remove Outermost Parentheses


#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>

using namespace std;

class Solution{
    public:
        string removeOuterParentheses(string s) {
            string ans = "";
            int count = 0;

            for(char c : s){
                if(count==0){
                    count=1;
                }else if(c == '('){
                    ans.push_back(c);
                    count++;
                }else if(c == ')' && count==1){
                    count=0;
                }else{
                    ans.push_back(c);
                    count--;
                }
            }
            return ans;
        }
        
};

int main(){
    Solution S;
    string str = "()";
    cout<<S.removeOuterParentheses(str);
}
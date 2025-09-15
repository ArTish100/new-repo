//1903. Largest Odd Number in String

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>

using namespace std;

class Solution{
    public:
        string largestOddNumber(string num) {
            int slen = num.length()-1;
            for(int i=slen;i>=0;i--){
                if((int)num[i]%2==1){
                    return num.substr(0,i+1);
                }
            }
            return "";
        }
        string largestOddNumber1(string num) {
            int cnt = -1;
            int slen = num.length();
            for(int i = 0 ; i < slen ; i++){
                if((int)num[i]%2!=0){
                    cnt=i;
                }
            }
            string ans = "";
            if(cnt==-1)
                return ans;
            for(int j=0;j<=cnt;j++){
                ans.push_back(num[j]);
            }
            return ans;
        }
        
};

int main(){
    Solution S;
    string str = "52";
    cout<<S.largestOddNumber(str)<<"[end]";
}

//8. String to Integer (atoi)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>


using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()){
            return 0;
        }
        int i=0;
        int slen = s.length();
        while(i<slen && (s[i]==' ' || s[i]==0)){
            i++;
        }
        if(i==slen)
            return 0;
        int sign = 1;
        if(s[i]=='-'){
            sign = -1;
            i++;
        }else if(s[i]=='+'){
            sign = 1;
            i++;
        }
        int temp = 0;
        long long ans = 0;
        while(isdigit(s[i]) && i<slen){
            temp = s[i]-'0';
            ans = ans*10 + temp;
            if(sign*ans>INT_MAX)
                return INT_MAX;
            if(sign*ans<INT_MIN)
                return INT_MIN;
            i++;
        }
        return (int)ans*sign;
        
    }
};

int main(){
    Solution S;
    string s1 = "-2147483648";
    cout<<S.myAtoi(s1);
}
#include <iostream>
#include <string.h>
using namespace std;


class Solution {
public:
    string calcsubstr(string s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        if(s.length()==1)
            return s;
        string maxstr=s.substr(0,1);
        for(int i=0;i<s.length()-1;i++){
            string odd=calcsubstr(s,i,i);
            string even=calcsubstr(s,i,i+1);
            if(odd.length()>maxstr.length()){
                maxstr=odd;
            }
            if(even.length()>maxstr.length()){
                maxstr=even;
            }
        }
        return maxstr;
    }
};
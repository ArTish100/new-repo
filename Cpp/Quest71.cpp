#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int slen = s.length();
            int l = 0;
            int r = slen - 1;
            cout<<slen;
            while(l<r){
                while(l<r && !isalnum(s[l])){
                    l++;
                }
                while(l<r && !isalnum(s[r])){
                    r--;
                }
                if(tolower(s[l])!=tolower(s[r]))
                    return false;
                cout<<l<<s[l]<<endl;
                cout<<r<<s[r]<<endl;
                l++;
                r--;
            }
            return true;
        }
};

int main(){
    Solution S;
    string s = "A man, a plan, a canal: Panama";
    cout<<S.isPalindrome(s);
}
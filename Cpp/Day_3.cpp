#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int left = 0;
        int right = 0;
        string k = "";
        for(int i = 0;i<s.length();i++){
            for(int l=0 ; l<k.length() ; l++){
                if(k[l]==s[i])
                    break;
                else
                    k.push_back(s[i]);
            }
        }
        return count;
    }
};

int main(){
    Solution S;
    string s = "pwwkew";
    int ans = S.lengthOfLongestSubstring(s);
    cout<<ans;
}
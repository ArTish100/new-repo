//205. Isomorphic Strings

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
    public:
        bool rotateString(string s, string goal) {
            int j=0;
            int slen = s.length();
            if(slen!=goal.length())
                return false;
            while(j<slen){
                if(s[0]!=goal[j]){
                    j++;
                    continue;
                }
                int k = slen;
                int ptr = j;
                while(k){
                    if(goal[ptr]==s[slen-k]){
                        ptr=(ptr+1)%slen;
                        k--;
                        if(k==0)
                            return true;
                    }else{
                        break;
                    }
                }
                j++;
            }
            return false;
        }
};

int main(){
    Solution S;
    string s1 = "ab";
    string s2 = "ba";
    cout<<S.rotateString(s1,s2);
}
//13. Roman to Integer

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {

    public:
    unordered_map<char,int> rtoi_map;
    Solution(){
        rtoi_map['I'] = 1;
        rtoi_map['V'] = 5;
        rtoi_map['X'] = 10;
        rtoi_map['L'] = 50;
        rtoi_map['C'] = 100;
        rtoi_map['D'] = 500;
        rtoi_map['M'] = 1000;
    }
    
    int romanToInt(string s) {
        int slen = s.length();
        int ans = 0;
        for(int i=0;i<slen;i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ans+=4;
                    i++;
                    continue;
                }else if(s[i+1]=='X'){
                    ans+=9;
                    i++;
                    continue;           
                }else{
                    ans+=1;
                }
            }else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ans+=40;
                    i++;
                    continue;
                }else if(s[i+1]=='C'){
                    ans+=90;
                    i++;
                    continue;           
                }else{
                    ans+=10;
                }
            }else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    ans+=400;
                    i++;
                    continue;
                }else if(s[i+1]=='M'){
                    ans+=900;
                    i++;
                    continue;           
                }else{
                    ans+=100;
                }
            }else{
                ans+=rtoi_map[s[i]];
            }
        }
        return ans;
    }
};

int main(){
    Solution S;
    string s1 = "MCMXCIV";
    cout<<S.romanToInt(s1);
}
//1781. Sum of Beauty of All Substrings

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>


using namespace std;

class Solution {

    public:
    int recurBeauty(string s){
        if(s.length()==1)
            return 0;
        int slen = s.length();
        int mini = slen;
        int maxi = 0;
        
        for(int i=0;i<slen;i++){
            
            
        }
        
    }
    int beautySum(string s) {
        int slen = s.length();
        int ans=0;
        for(int i=0;i<slen;i++){
            unordered_map<char,int> u_map;
            for(int j=i;j<slen;j++){
                u_map[s[j]]+=1;
                int mini = slen;
                int maxi = 0;
                for(auto it : u_map){
                    mini = min(it.second,mini);
                    maxi = max(it.second,maxi);
                }
                ans += maxi-mini;
            }
        }
        return ans;
    }
};

int main(){
    Solution S;
    string s1 = "aabcb";
    cout<<S.beautySum(s1);
}
//151. Reverse Words in a String

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>

using namespace std;

class Solution{
    public:
        string reverseWords(string s) {
            string ans = "";
            reverse(s.begin(),s.end());
            int slen = s.length();
            int l = 0;
            int r = 0;
            while(r<=slen){
                if(s[l]==' '){
                    l++;
                    r++;
                }else if(s[r]==' ' || r==slen){
                    if(!ans.empty() && s[r-1]!=' ')
                        ans.push_back(' ');
                    for(int itr=r-1;itr>=l;itr--){
                        ans.push_back(s[itr]);
                    }
                    if(r==slen)
                        break;
                    
                    l=r;
                    
                }else{
                    r++;
                }
            }
            return ans;
        }
        
};

int main(){
    Solution S;
    string str = " ";
    cout<<S.reverseWords(str)<<"[end]";
}
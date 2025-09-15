//14. Longest Common Prefix

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
        string compareAnsVecElem(string ans, string a){
            int slen = min(ans.length(),a.length());
            cout<<ans<<" "<<a<<endl;
            int count = 0;
            for(int i=0;i<slen;i++){
                if(ans[i]==a[i]){
                    count++;
                }else{
                    break;
                }
            }
            cout<<count<<endl;
            return a.substr(0,count);
        }

        string longestCommonPrefix(vector<string>& strs) {
            string ans = strs[0];
            string temp;
            for(string a : strs){
                temp.append(compareAnsVecElem(ans, a));
                ans.clear();
                ans.append(temp);
                temp.clear();
            }
            return ans;
        }
};

int main(){
    Solution S;
    vector<string> vec = {"cir","car"};
    cout<<S.longestCommonPrefix(vec);
}
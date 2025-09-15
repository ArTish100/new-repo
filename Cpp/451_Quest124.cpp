//451. Sort Characters By Frequency

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            int slen = s.length();
            sort(s.begin(),s.end());
            map<int,string> s_map;
            int r=0;
            int l=0;
            while(r!=slen){
                if(s[l]==s[r]){
                    r++;
                }else{
                    if(!(s_map.find(r-l)==s_map.end())){
                        s_map[r-l].append(s.substr(l,r-l));    
                    }else{
                        s_map[r-l] = s.substr(l,r-l);
                    }
                    
                    l=r;
                }
                if(r==slen){
                    if(!(s_map.find(r-l)==s_map.end())){
                        s_map[r-l].append(s.substr(l,r-l));    
                    }else{
                        s_map[r-l] = s.substr(l,r-l);
                    }
                }
            }
            string ans;
            for(auto a : s_map){
                ans.append(a.second);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};

int main(){
    Solution S;
    string s1 = "aaassssd";
    cout<<S.frequencySort(s1);
}
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);
        int l=pref[0];
        for(int i=0;i<pref.size()-1;i++){
                l=pref[i]^pref[i+1];    
                ans.push_back(l);
            }
            
        
        return ans;
    }
};
int main(){
    Solution S;
    vector<int> v={1,2,3,4,5};
    vector<int> va=S.findArray(v);
    for(int i=0;i<va.size();i++){
        cout<<va[i]<<endl;
    }
}
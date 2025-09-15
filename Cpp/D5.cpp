#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        if(s.length()==2 && s[0]==s[1])
            return 1;
        vector<string> k;
        string sub;
        for(char c : s){
            bool flag=true;
            sub.push_back(c);
            if(k.size()==0){
                k.push_back(sub);
                sub.clear();
                continue;
            }else{
                for(int i=0;i<k.size();i++){
                    if(sub==k[i]) flag=false;
                }
                if(flag){
                    k.push_back(sub);
                    sub.clear();
                }
            }
        }
        for(string c : k){
            cout<<c<<" ";
        }
        return k.size();
    }
};
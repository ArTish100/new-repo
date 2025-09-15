#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int max=0;
        int i;
        string grt;
        int val;
        if(x>=y){
            grt="ab";
            val=x;
        }else{
            grt="ba";
            val=y;
        }
        int strs=s.length();
        string news="";
        for(i=0;i<strs-1;i++){
            if(s[i]==grt[0] && s[i+1]==grt[1]){
                max+=val;
                for(int j=i+2;j<strs;j++){
                    news.push_back(s[j]);
                }
                i=0;
                s=news;
                strs=s.length();
                
            }else
                news.push_back(s[i]);
        }
        
        news.erase();
        cout<<news<<endl;
        if(grt=="ab"){
            grt="ba";
            val=y;
        }
        else{
            grt="ab";
            val=x;
        }
        s=news; 
        cout<<s<<endl;
        news="";
        for(i=0;i<strs-1;i++){
            if(s[i]==grt[0] && s[i+1]==grt[1]){
                max+=val;
                for(int j=i+2;j<strs;j++){
                    news.push_back(s[j]);
                }
                i=-1;
                s=news;
                strs=s.length();
                
            }else
                news.push_back(s[i]);
        }
        return max;
    }
};  
int main(){
    Solution S;
    int a = S.maximumGain("cdbcbbaaabab",5,4);
    cout<<a;
}
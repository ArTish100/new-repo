#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long count_1 = 0;
        long n=0;
        long i=0;
        long j=0;
        long end_point=0;
        long long steps=0;
        for(auto a : s){
            if(a=='1' && i==0){
                i=count_1;    
            }
            n++;
        }
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            end_point++;
            if(*it=='0')
                break;
        }
        cout<<end_point<<endl;
        cout<<i<<endl;
        end_point=n-end_point;
        while(end_point>i){
            for(j;j<end_point;j++){
                cout<<"works";
                if(s[j]=='1' && s[j+1]=='0'){
                    swap(s[j],s[j+1]);
                    cout<<"works";
                    steps+=1;
                }
            }
            i+=1;
            j=i;
            end_point-=1;
        }
        return steps;
    }
};

int main(){
    Solution S;
    string s="00100110011111";
    cout<<S.minimumSteps(s);
}


/*
00"1"00110"0"11111
*/
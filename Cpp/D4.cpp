#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int max = 0;
        for(int i=0;i<n;i++){
            if(s[i]<s[i+1] && max==0){
                max=i+1;
            }else if(max!=0){
                s[max]<=s[i] ? max=i : max;
            }
        }
        cout<<max<<endl;
        for (int i = 0; i < n; i++) {
            if (s[i] < s[max] && max!=0) {
                swap(s[i], s[max]);
                break;
            }
        }
        return stoi(s);
    }
};

int main(){
    Solution S;
    int s=1993;
    cout<<S.maximumSwap(s);
}


/*
00"1"00110"0"11111
*/
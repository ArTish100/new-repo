#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int s=(to_string(x)).length();
        int a=1;
        int i;
        for(i=1;i<s;i++){
            a=a*10;
        }
        for(i=0;i<s/2;i++){
            if(x%10!=x/a){
                return false;
            }
            x=x-(x/a)*a;
            a=a/100;
            x=x/10;
        }
        return true;
    }
};

int main(){
    Solution S1;
    bool a = S1.isPalindrome(11211);
    cout<<a;
}
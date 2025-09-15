//Excel Sheet Column NUmber
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int s=int(columnTitle.size());
        // (sizeof(columnTitle));
        int sum=0;
        for(int i=0;i<s;i++){
            int ctype=(int(columnTitle[i]))-64;
            double p=pow(24+2,s-i-1);
            int a=ctype*p;
            sum=sum+a;
        }
        return int(sum);
    }
};

int main(){
    Solution S1;
    int arg=S1.titleToNumber("A");
    std::cout<<arg;
}
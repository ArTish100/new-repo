//Pow(x,n)

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    void printAns(vector<int> ans){
        for(int a:ans){
            cout<<a<<" "<<endl;
        }
    }
    double myPow(double x, int n) {
        int nn = abs(n);
        double ans = 1;
        while(nn){
            if(nn&1){
                ans*=x;
                nn-=1;
            }else{
                x*=x;
                nn/=2;
            }
        }
        if(n<0)
            return (double)1/ans;
        return ans;
    }
};

int main(){
    Solution S;
    double ans;
    ans = S.myPow(5,2);
    cout<<ans;
}
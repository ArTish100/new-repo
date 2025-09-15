//50. Pow(x, n)

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long n_long = n;
        if(n<0)
            n_long = -1*n_long;
        while(n_long){
            if(n_long%2==1){
                ans = ans*x;
                n_long-=1;
            }else{
                x = x*x;
                n_long = n_long/2;
            }
        }
        if(n<0)
            return (double)1.0/(double)ans;
        return ans;
    }
    
};

int main(){
    Solution S;
    cout<<S.myPow(2,-1);
}
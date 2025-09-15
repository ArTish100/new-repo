//204. Count Primes

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
    void intprintAns(vector<int> ans){
        for(int a:ans){
            cout<<a<<" "<<endl;
        }
    }
    int countPrimes(int n) {
        vector<bool> vec(n+1,true);
        int sqn = sqrt(n);
        for(int i=2;i<=sqn;i++){
            if(vec[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    vec[j] = false;
                }
            }
        }
        int rans;
        for(int i=2;i<=n;i++){
            if(vec[i] && n%i==0)
                rans++;
        }
        return rans;
    }
};

int main(){
    Solution S;
    int ans;
    ans = S.countPrimes(1);
    cout<<ans;
}
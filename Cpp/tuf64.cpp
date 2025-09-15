//Prime Factorization using Sieve

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
    vector<int> findPrimeFactors(int n) {
        vector<bool> vec(n+1,true);
        int sqn = sqrt(n);
        for(int i=2;i<=sqn;i++){
            if(vec[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    vec[j] = false;
                }
            }
        }
        vector<int> rans;
        for(int i=2;i<=n;i++){
            if(vec[i] && n%i==0){
                while(n%i==0){
                    n/=i;
                    rans.push_back(i);
                }
            }
        }
        if(n>1){
            rans.push_back(n);
        }
        return rans;
    }
};

int main(){
    Solution S;
    vector<int> ans;
    ans = S.findPrimeFactors(1520);
    S.intprintAns(ans);
}
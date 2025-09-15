//1922. Count Good Numbers

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long perm(long long oore, long long whutev, long long moduloo){
        long long ans = 1;
        while(whutev>0){
            if(whutev%2){
                ans = ans*oore%moduloo;
                whutev-=1;
            }else{
                oore = oore*oore%moduloo;
                whutev = whutev/2;
            }
        }
        cout<<ans<<endl;
        return ans%moduloo;
    }

    int countGoodNumbers(long long n) {
        long long no_even = (n+1)/2;
        long long no_odd = (n)/2;
        long long modul = 7+1e+9;
        cout<<perm(5,no_even,modul)<<endl;
        cout<<perm(4,no_odd,modul)<<endl;
        return perm(5,no_even,modul)*perm(4,no_odd,modul)%modul;
    }
};

int main(){
    Solution S;
    cout<<S.countGoodNumbers(50);
}
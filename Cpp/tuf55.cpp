//Count set bits

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string num2binary(int target){
        string ans="";
        while(target!=1){
            ans+=target%2+'0';
            target = target/2;
        }
        ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int countSetBits(int n) {
        int ans = 0;
        while(n){
            n = n&(n-1);
            ans++;
        }
        return ans;
    }
    int countSetBits1(int n) {
        int ans=0;
        while(n!=1){
            ans += n%2;
            n = n/2;
        }
        ans+=1;
        return ans;
    }
};

int main(){
    Solution S;
    int n = 15;
    cout<<S.countSetBits(n);
}
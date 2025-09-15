//Check if the i-th bit is Set or Not

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
    bool checkKthBit(int n, int k) {
        n = n>>k;
        cout<<n<<endl;
        cout<<num2binary(n)<<endl;
        return n%2;
    }
};

int main(){
    Solution S;
    int n = 27818;
    int k = 1;
    string ans = S.num2binary(n);
    cout<<ans<<endl;
    cout<<S.checkKthBit(n, k);
}
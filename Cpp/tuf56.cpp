//Set the rightmost unset bit

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
    int setBit(int n) {
        return (n+1)|n;
    }
};

int main(){
    Solution S;
    int n = 15;
    cout<<S.num2binary(n)<<endl;
    n = S.setBit(n);
    cout<<n<<endl;
    cout<<S.num2binary(n);
}
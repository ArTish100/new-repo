//Check if a Number is Odd or Not

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
    bool isOdd(int n) {
        return (n&1);
    }
};

int main(){
    Solution S;
    int n = 27818;
    cout<<S.isOdd(n);
}
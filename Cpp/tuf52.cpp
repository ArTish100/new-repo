//37. Sudoku Solver

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
        return ans;
    }
    int binary2num(string sans){
        int pow2 = 1;
        int ans=0;
        while(!sans.empty()){
            ans = ans+pow2*(sans.back()-'0');
            pow2=pow2*2;
            sans.pop_back();
        }
        return ans;
    }
};

int main(){
    Solution S;
    int target = 5;
    string ans = S.num2binary(target);
    cout<<ans<<endl;
    cout<<S.binary2num(ans);
}
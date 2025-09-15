//Find xor of numbers from L to R

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findXOR(int n){
        if(n%4==0) return n;
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
    }
    int findXOR(int l, int r) {
        return findXOR(l-1)^findXOR(r);
    }
};

int main(){
    Solution S;
    int ans;
    ans = S.findXOR(4,6);
    cout<<ans;
}
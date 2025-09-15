//2220. Minimum Bit Flips to Convert Number

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int ans = 0;
        while(cnt<=31){
            if((start & 1<<cnt) != (goal & 1<<cnt)){
                ans++;
            }
            cnt++;
        }
        cout<<ans<<endl;
        return ans;
    }
    
};

int main(){
    Solution S;
    int ans = S.minBitFlips(3,4);
    cout<<ans<<endl;
}
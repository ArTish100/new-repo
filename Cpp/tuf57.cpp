//Swap two numbers

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    pair<int, int> get(int a, int b) {
        a = a ^ b;
        b = b ^ a;
        a = a ^ b;
        return {a,b};
    }
};

int main(){
    Solution S;
    pair<int,int> ans;
    ans = S.get(13, 9);
    cout<< ans.first<<" "<< ans.second<<endl;
}
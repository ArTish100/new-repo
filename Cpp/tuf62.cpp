//All divisors of a Number

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
    void printAns(vector<int> ans){
        for(int a:ans){
            cout<<a<<" "<<endl;
        }
    }
    vector<int> primeFac(int n) {
        int rtn = sqrt(n);
        vector<int> ans={1};
        for(int i=2;i<=rtn;i++){
            if(n%i==0){
                ans.push_back(i);
                if(n/i!=i)
                    ans.push_back(n/i);
            }
        }
        sort(ans.begin(),ans.end());
        if(n>=2)
            ans.push_back(n);
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> ans;
    ans = S.primeFac(4);
    S.printAns(ans);
}
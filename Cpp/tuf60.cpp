//Two odd Occuring

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printAns(vector<int> ans){
        for(int a:ans){
            cout<<a<<" "<<endl;
        }
    }
    vector<int> twoOddNum(vector<int>& arr) {
        int ans = 0;
        vector<int> vec;
        for(int a : arr){
            ans^=a;
        }
        int k=(ans&(ans-1))^ans;
        ans = 0;
        int n1=0;
        int n2=0;
        for(int a : arr){
            if(a&k)
                n1 = n1^a;
            else
                n2 = n2^a;
        }
        if(n1>n2)
            return {n1,n2};
        else
            return {n2,n1};
    }
};

int main(){
    Solution S;
    vector<int> ans;
    vector<int> vec = {1, 7, 5, 7, 5, 4, 7, 4};
    ans = S.twoOddNum(vec);
    S.printAns(ans);
}
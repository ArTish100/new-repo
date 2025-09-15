#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(int a : nums){
            xor1 = xor1^a;
        }
        return xor1;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {0,2,0};
    //S.moveZeroes(vec);
    S.printVec(vec);
    cout<<S.singleNumber(vec);
}
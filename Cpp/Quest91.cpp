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
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = 0;
        int i = 0;
        for(int i : nums){
            if(a!=i)
                return a;
            a++;
        }
        return a;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {2,1};
    //S.moveZeroes(vec);
    S.printVec(vec);
    cout<<S.missingNumber(vec);
}
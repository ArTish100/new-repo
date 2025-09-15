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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int nlen = nums.size();
        if(nlen==1)
            return nums[0];
        int maxone = 0;
        int count = nums[0];
        for(int i=1;i<nlen;i++){
            if(nums[i]==1 && nums[i-1]==nums[i]){
                count++;
            }else if(count!=1 && nums[i]==1){
                count = 1;
                cout<<"did";
            }
            if(count>maxone)
                maxone = count;
        }
        return maxone;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {0};
    //S.moveZeroes(vec);
    S.printVec(vec);
    cout<<S.findMaxConsecutiveOnes(vec);
}
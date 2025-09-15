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
    }
    void moveZeroes(vector<int>& nums) {
        int nlen = nums.size();
        if(nlen==1)
            return;
        int b = -1;
        int i = 0;
        for(i;i<nlen;i++){
            if(nums[i]==0 && b==-1)
                b = i;
            else if(b<i && b!=-1){
                nums[b] = nums[i];
                nums[i] = 0;
                while(nums[b]!=0)
                    b++;
            }
        }
    }
};

int main(){
    Solution S;
    vector<int> vec = {1};
    S.moveZeroes(vec);
    S.printVec(vec);
}
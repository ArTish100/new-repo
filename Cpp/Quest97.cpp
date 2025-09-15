//31. Next Permutation


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    void nextPermutation(vector<int>& nums) {
        int nlen = nums.size();
        int ind = -1;
        for(int i=nlen-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nlen-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
                
        }
        reverse(nums.begin()+ind+1,nums.end());
        return;
            
    }
};


int main(){
    Solution S;
    vector<int> vec = {2, 1, 5, 4, 3, 0, 0};
    S.printVec(vec);
    S.nextPermutation(vec);
    S.printVec(vec);
}
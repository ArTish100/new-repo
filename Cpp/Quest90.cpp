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
    void reverseVector(vector<int>& nums, int l, int r) {
        int nlen = nums.size();
        int k;
        while(l<r){
            k = nums[l];
            nums[l] = nums[r];
            nums[r] = k;
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int nlen = nums.size();
        if(nlen == 1)
            return;
        reverseVector(nums, nlen-k, nlen-1);
        reverseVector(nums, 0, nlen-k-1);
        reverseVector(nums, 0, nlen-1);
    }
};

int main(){
    Solution S;
    vector<int> vec = {1,2};
    int k = 3;
    S.rotate(vec,k);
    S.printVec(vec);
}
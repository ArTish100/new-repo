#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int piv;
        piv=nums.size()/2;
        int high = nums.size();
        int count=0;
        divsubarray(nums,k,0,high,count);
    }
    int divsubarray(vector<int>& nums, int k, int low, int high, int c){
        if(low==high)
            return low,high,nums[low];
        else{
            int mid = (low+high)/2;
            int l_l, l_h, l_sum;
            int r_l, r_h, r_sum;
            l_l, l_h, l_sum = divsubarray(nums, k, low, mid, c);
            r_l, r_h, r_sum = divsubarray(nums, k, mid+1, high, c);
            if(l_sum%k==0){
                c++;
                return(l_l, l_h, l_sum, c);
            }
            if(r_sum%k==0){
                c++;
                return(r_l, r_h, r_sum, c);
            }
            
        }
    }
    int crosssum(vector<int>& nums, int k, int low, int mid, int high){

    }
};

int main(){
    Solution S;
    vector<int> nums({4,5,0,-2,-3,1});
    int k = S.subarraysDivByK(nums,5);
    cout<<k;
}
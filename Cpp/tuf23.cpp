//Find out how many times the array has been rotated


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
    public:
        int min(int a, int b){
            if(a<b)
                return a;
            return b;
        }
        int findMin(vector<int>& nums){
            int l=0;
            int r=nums.size()-1;
            int m;
            int min = 0;
            while(l<=r){
                m = l+(r-l)/2;
                if(nums[min]>nums[m])
                    min = m;
                if(nums[m]>=nums[l] && nums[m]<nums[r]){
                    if(nums[min]>nums[l])
                        min = l;
                    return min;
                }else if(nums[m]<nums[l] && nums[m]<=nums[r]){
                    r = m-1;
                }else{
                    l = m + 1;
                }
            }
            return min;
        }
};


int main(){
    Solution S;
    vector<int> vec = {-2,-1,0,1,-3};
    cout<<S.findMin(vec);
}
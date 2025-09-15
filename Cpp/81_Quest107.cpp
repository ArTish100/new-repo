//81. Search in Rotated Sorted Array II

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
    public:
        bool search(vector<int>& nums, int target){
            int l=0;
            int r=nums.size()-1;
            int m;
            while(l<=r){
                m = l+(r-l)/2;
                if(nums[m]==target)
                    return 1;
                if(nums[l]==nums[r] && nums[l]==nums[m]){
                    l++;
                    r--;
                    continue;
                }else if(nums[l]<=nums[m]){
                    if(nums[m]<target || target<nums[l]){
                        l=m+1;
                    }else{
                        r=m-1;
                    }
                }else{
                    if(nums[m]>target || target>nums[r]){
                        r=m-1;
                    }else{
                        l=m+1;
                    }
                }
            }
            return 0;
        }
};


int main(){
    Solution S;
    vector<int> vec = {1,1,1,0,1};
    cout<<S.search(vec, 0);
}
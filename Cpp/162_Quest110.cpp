//162. Find Peak Element


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
    public:
        int findPeakElement(vector<int>& nums){
            int l=1;
            int nlen = nums.size();
            int r=nlen-2;
            int m;
            if(nlen==1)
                return 0;
            if(nums[1]<nums[0])
                return 0;
            if(nums[nlen-1]>nums[nlen-2])
                return nlen-1;
            while(l<=r){
                m = l+(r-l)/2;
                if(nums[m]>nums[m-1] && nums[m+1]<nums[m])
                    return m;    
                else if(nums[m]>nums[m-1]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            return -1;
        }
};


int main(){
    Solution S;
    vector<int> vec = {1,2,1,3,5,6,4};
    cout<<S.findPeakElement(vec);
}
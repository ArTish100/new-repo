//540. Single Element in a Sorted Array


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
    public:
        int singleNonDuplicate(vector<int>& nums){
            int l=1;
            int nlen = nums.size();
            int r=nlen-2;
            int m;
            if(nlen==1)
                return nums[0];
            if(nums[1]!=nums[0])
                return nums[0];
            if(nums[nlen-1]!=nums[nlen-2])
                return nums[nlen-1];
            while(l<=r){
                m = l+(r-l)/2;
                if(nums[m]!=nums[m-1] && nums[m+1]!=nums[m])
                    return nums[m];    
                if((m%2==0 && nums[m]==nums[m+1]) || (m%2==1 && nums[m]==nums[m-1])){
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
    vector<int> vec = {1,1,2,3,3,4,4,8,8};
    cout<<S.singleNonDuplicate(vec);
}
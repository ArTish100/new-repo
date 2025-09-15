//Finding Sqrt of a number using Binary Search


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
    public:
        int findSqrt(int nums){
            if(nums == 1 || nums == 0)
                return nums;
            int l = 0;
            int r = nums-1;
            int m;
            int ans;
            while(l<=r){
                m = l+(r-l)/2;
                if(m*m<=nums){
                    ans = m;
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            return ans;
        }
};


int main(){
    Solution S;
    vector<int> vec = {1,2,1,3,5,6,4};
    cout<<S.findSqrt(9);
}
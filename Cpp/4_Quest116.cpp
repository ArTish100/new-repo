//4. Median of Two Sorted Arrays

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public : 
        int maxVal(vector<int> nums){
            int maxi = -1;
            for(auto a : nums){
                maxi = max(maxi,a);
            }
            return maxi;
        }

        int findMaxDist(vector<int> nums){
            int maxdist = 0;
            int nlen = nums.size();
            for(int i=1;i<nlen;i++){
                maxdist = max(nums[i]-nums[i-1],maxdist);
            }
            return maxdist;
        }

        int calcVal(vector<int> nums, long double m){
            int div;
            int cnt = 0;
            int nlen = nums.size();
            for(int i=1;i<nlen;i++){
                div = (nums[i]-nums[i-1])/m;
                
                if((div*m)==(nums[i]-nums[i-1])){
                    div--;
                }
                cnt+=div;
            }
            return cnt;
        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int nlen1 = nums1.size();
            int nlen2 = nums2.size();
            if(nlen1>nlen2)
                return findMedianSortedArrays(nums2,nums1);
            int n = (nlen1+nlen2);
            int l = 0;
            int cmp;
            if(n%2 == 0)
                cmp = n/2;
            else
                cmp = (n/2)+1;
            int r = nlen1;
            int l1;
            int l2;
            int r1;
            int r2;
            while(l<=r){
                int m1 = l+(r-l)/2;
                int m2 = cmp-m1;
                int l1 = INT_MIN, l2 = INT_MIN;
                int r1 = INT_MAX, r2 = INT_MAX;
                if (m1 < nlen1) r1 = nums1[m1];
                if (m2 < nlen2) r2 = nums2[m2];
                if (m1 - 1 >= 0) l1 = nums1[m1 - 1];
                if (m2 - 1 >= 0) l2 = nums2[m2 - 1];
                if (l1 <= r2 && l2 <= r1) {
                    if (n % 2 == 1)
                        return max(l1, l2);
                    else
                        return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
                }else if (l1 > r2)
                    r = m1 - 1;
                else 
                    l = m1 + 1;
            }
            return 0;
                
            
        }   
};

int main(){
    Solution S;
    vector<int> vec1 = {1};
    vector<int> vec2 = {3,4,5};
    cout<<S.findMedianSortedArrays(vec1,vec2);
}

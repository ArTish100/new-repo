//K-th Element of two sorted arrays

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public : 
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int target){
            int nlen1 = nums1.size();
            int nlen2 = nums2.size();
            if(nlen1>nlen2)
                return findMedianSortedArrays(nums2, nums1, target);
            int l = max(0, target-nlen2);
            int r = min(target, nlen1);
            int m1;
            int m2;
            while(l<=r){
                m1 = l+(r-l)/2;
                m2 = target - m1;
                int l1 = INT_MIN;
                int l2 = INT_MIN;
                int r1 = INT_MAX;
                int r2 = INT_MAX;
                if(m1<nlen1)
                    r1 = nums1[m1];
                if(m2<nlen2)
                    r2 = nums2[m2];
                if(m1-1>=0)
                    l1 = nums1[m1-1];
                if(m2-1>=0)
                    l2 = nums2[m2-1];
                if(l1<=r2 && l2<=r1){
                    return max(l1,l2);
                }else if(l1>r2){
                    r = m1-1;
                }else{
                    l = m1+1;
                }
            }
            return 0;
        }

        double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2, int target) {
            int ptr1 = 0;
            int ptr2 = 0;
            int n1 = nums1.size();
            int n2 = nums2.size();
            int cnt = 1;
            int n = n1+n2;
            int ans;
            while(cnt!=target+1){
                if(ptr1>=n1 || ptr2>=n2)
                    break;
                if(nums1[ptr1]<=nums2[ptr2]){
                    ans=nums1[ptr1];
                    ptr1++;
                }else if(nums1[ptr1]>nums2[ptr2]){
                    ans=nums2[ptr2];
                    ptr2++;
                } 
                cnt++;
            }
            if(cnt==target+1) return ans;
            if(ptr1>=n1)
                while(cnt!=target+1){
                    ans = nums2[ptr2];
                    ptr2++;
                    cnt++;
                }
            else
                while(cnt!=target+1){
                    ans = nums1[ptr1];
                    ptr1++;
                    cnt++;
                }
            return ans;
        }   
};

int main(){
    Solution S;
    vector<int> vec1 = {1,2,3,5};
    vector<int> vec2 = {4,5,6,7};
    cout<<S.findMedianSortedArrays(vec1,vec2,8);
}

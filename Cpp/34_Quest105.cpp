//34. Find First and Last Position of Element in Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
public:
    void printVec(vector<vector<int>> nums){
        for(auto a : nums){
            for(auto b : a)
                cout<<b<<" ";
            cout<<endl;
        }
        cout<<endl;
    }

    void printVec_lin(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
        
        return;
    }

    int searchRangeStart(vector<int>& nums, int target) {
        int l = 0;
        int start=-1;
        int nlen = nums.size();
        int r = nlen-1;
        int m ;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]>target){
                r=m-1;
            }else if(nums[m]<target){
                l=m+1;
            }else{
                start = m;
                r = m-1;
            }
        }
        return start;
    }

    int searchRangeEnd(vector<int>& nums, int target) {
        int l = 0;
        int end=-1;
        int nlen = nums.size();
        int r = nlen-1;
        int m ;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]>target){
                r=m-1;
            }else if(nums[m]<target){
                l=m+1;
            }else{
                end = m;
                l = m+1;
            }
        }
        return end;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchRangeStart(nums,target),searchRangeEnd(nums,target)};
    }

    

};

int main(){
    Solution S;
    vector<int> vec1 = {5,7,7,8,8,10};
    S.printVec_lin(vec1);
    S.printVec_lin(S.searchRange(vec1,8));
}






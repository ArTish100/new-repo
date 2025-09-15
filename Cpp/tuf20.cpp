//35. Floor and Ceil in Sorted Array

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

    int floorAndCeil(vector<int>& nums, int target) {
        int l = 0;
        int floor=nums.size()-1;
        int ceil=nums.size()-1;
        int r = nums.size()-1;
        int m ;

        
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]>target){
                floor = m;
                r=m-1;
            }else if(nums[m]<target){
                ceil = m;
                l=m+1;
            }else{
                floor = m;
                ceil = m;
                break;
            }
        }
        cout<<"floor "<<nums[floor]<<" ceil "<<nums[ceil]<<endl;
        return 1;
    }

    

};

int main(){
    Solution S;
    vector<int> vec1 = {3, 4, 4, 7, 8, 10};
    S.printVec_lin(vec1);
    cout<<"ans "<<S.floorAndCeil(vec1,8);
}





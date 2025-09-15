//704. Binary Search

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

    int search(vector<int>& nums, int target) {
        int l=0;
        int nlen = nums.size();
        int r=nlen-1;
        int m;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]>target){
                r=m-1;
            }else if(nums[m]<target){
                l=m+1;
            }else{
                return m;
            }
        }
        return -1;
    }

};

int main(){
    Solution S;
    vector<int> vec1 = {-1,0,3,5,9,12};
    S.printVec_lin(vec1);
    cout<<S.search(vec1,2);
}




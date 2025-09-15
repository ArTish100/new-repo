//Lower bound

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
        int smolind=0;
        while(l<r){
            m = l+(r-l)/2;
            if(nums[m]>=target){
                smolind = m;
                r=m-1;
            }else if(nums[m]<target){
                l=m+1;
            }
        }
        return smolind;
    }

    int search1(vector<int>& nums, int target) {
        int l=0;
        int nlen = nums.size();
        int r=nlen-1;
        int m;
        int ans=0;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]>target){
                cout<<m<<endl;
                ans = m;
                r=m-1;
            }else{
                l=m+1;
                
            }
        }
        return ans;
    }

};

int main(){
    Solution S;
    vector<int> vec1 = {1,2,2,3};
    S.printVec_lin(vec1);
    cout<<"ans "<<S.search1(vec1,2);
}




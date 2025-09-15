//35. Search Insert Position

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

    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int ans=nums.size();
        int r = ans-1;
        int m ;
        
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]>=target){
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
    vector<int> vec1 = {3, 4, 4, 7, 8, 10};
    S.printVec_lin(vec1);
    cout<<"ans "<<S.searchInsert(vec1,8);
}





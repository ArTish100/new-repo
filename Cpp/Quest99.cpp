/*
560. Subarray Sum Equals K
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
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
    }
    void recursionSubarr(vector<int>& nums, int k, int l, int r, int nlen, int& count, int& sums){
        if(r>nlen)
            return;
    }
    int subarraySum(vector<int>& nums, int k) {
        int l=0;
        int nlen = nums.size();
        int r=nlen-1;
        int sums;
        int count=0;
        for(int i=l;i<=r;i++){
            sums = 0;
            for(int j=i;j<=r;j++){
                cout<<sums<<endl;
                sums+=nums[j];
                if(sums==k)
                    count++;
            }
        }
        return count;
        
    }


};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<int> vec = {-1,-1,1};
    S.printVec_lin(vec);
    cout<<S.subarraySum(vec,0);
}

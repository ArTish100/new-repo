/*
560. Subarray Sum Equals K

Mapping approach 
pre sum approach

*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
        map<int,int> n_map;
        int nlen = nums.size();
        int sums = 0;
        int count = 0;
        int remain_sum;
        n_map[0]=1;
        for(int i=0;i<nlen;i++){
            sums += nums[i];
            remain_sum = sums - k;
            count += n_map[remain_sum];
            n_map[sums] += 1;
        }
        return count;   
    }


};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<int> vec = {3,1,2,4};
    S.printVec_lin(vec);
    cout<<S.subarraySum(vec,6);
}

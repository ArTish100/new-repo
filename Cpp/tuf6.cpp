//Kadane's Algorithm : Maximum Subarray Sum in an Array
//Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
//has the largest sum and returns its sum and prints the subarray.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    vector<int> largeSum(vector<int> nums) {
        int sum = 0;
        vector<int> ans;
        int maxs = 0;
        for(int a : nums){
            if(sum<0){
                sum=0;
                ans.clear();
            }
            sum+=a;
            if(sum>maxs)
                maxs = sum;
            ans.push_back(a);
        }
        int k;
        while(sum!=maxs){
            sum=sum-*ans.end();
            if(sum!=maxs)
                ans.pop_back();
        }
        cout<<sum<<endl;
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    S.printVec(vec);
    S.printVec(S.largeSum(vec));
}
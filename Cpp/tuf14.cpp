//Find the repeating and missing numbers


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

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

    void repAndMissNum(vector<int>& nums) {
        int nlen = nums.size();
        int sum = (nlen+1)*nlen/2;
        int sum_sq = (2*nlen+1)*(nlen+1)*nlen/6;
        int nsum=0;
        int nsum_sq=0;
        for(int i=0;i<nlen;i++){
            nsum+=nums[i];
            nsum_sq+=nums[i]*nums[i];
        }
        sum = sum-nsum;
        sum_sq = sum_sq-nsum_sq;
        sum_sq = sum_sq/sum;
        cout<<(sum+sum_sq)/2<<endl;
        cout<<(-1*sum+sum_sq)/2<<endl;
        
    }

};

int main(){
    Solution S;
    vector<int> vec1 = {3,1,2,5,4,6,7,5};
    S.printVec_lin(vec1);
    S.repAndMissNum(vec1);
}



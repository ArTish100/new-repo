//Count the number of subarrays with given xor K


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
    }

    int longSubarrWithXorSum(vector<int>& nums, int target) {
        int sums=0;
        int nlen = nums.size();
        int prefXor;
        int count = 0;
        unordered_set<int> n_map;
        int maxLen=0;
        for(int i=0;i<nlen;i++){
            sums^=nums[i];
            cout<<sums<<endl;
            prefXor=sums^target;
            if(sums==target){
                count++;
            }else{
                if(n_map.find(prefXor)!=n_map.end()){
                    count++;
                }else{
                    n_map.insert(sums);
                }
            }
        }
        return count++;
    }
};

int main(){
    Solution S;
    vector<int> vec = {5, 6, 7, 8, 9}; //-5,-4,-2,-2,-2,-1,0,0,1
    S.printVec_lin(vec);
    cout<<(6^7^8^9^5)<<endl;
    cout<<S.longSubarrWithXorSum(vec,5);
}



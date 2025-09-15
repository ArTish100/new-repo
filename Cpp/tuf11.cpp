//Length of the longest subarray with zero Sum


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

    int longSubarrWithZeroSum(vector<int>& nums) {
        int sums=0;
        int nlen = nums.size();
        int prefSum;
        unordered_map<int,int> n_map;
        int maxLen=0;
        for(int i=0;i<nlen;i++){
            sums+=nums[i];
            prefSum=0+sums;
            if(sums==0){
                n_map[0]=i;
                maxLen = max(maxLen,n_map[0]+1);
            }else{
                if(n_map.find(sums)!=n_map.end()){
                    maxLen = max(maxLen,i-n_map[sums]);
                }else{
                    n_map[sums]=i;
                    cout<<sums<<" "<<i<<endl;
                }
                
                
            }
        }
        return maxLen;
    }
};

int main(){
    Solution S;
    vector<int> vec = {1, 3, -5, 6, -2}; //-5,-4,-2,-2,-2,-1,0,0,1
    S.printVec_lin(vec);
    cout<<S.longSubarrWithZeroSum(vec);
}



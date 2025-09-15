//15. 3Sum


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

    vector<vector<int>> threeSum(vector<int>& nums) {
        int nlen = nums.size();
        int i,j,k,sums;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<nlen-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            j = i+1;
            k = nlen-1;
            while(j<k){
                sums = nums[i] + nums[j] + nums[k];
                if(sums>0){
                    j++;
                }else if(sums<0){
                    k--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                    while(k>j && nums[k]==nums[k+1])
                        k--;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {-1,0,1,2,-1,-4};
    S.printVec_lin(vec);
    S.printVec(S.threeSum(vec));
}



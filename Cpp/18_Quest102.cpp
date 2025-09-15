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

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int nlen = nums.size();
        int i,j,k,l;
        long long sums;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nlen;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nlen;j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                k = j+1;
                l = nlen-1;
                while(k<l){
                    sums = nums[i] + nums[j] + nums[k] + nums[l];
                    if(1){
                        if(sums>target)
                            l--;
                        else if(sums<target)
                            k++;
                        else{
                            ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                            k++;
                            l--;
                            while(k<l && nums[k]==nums[k-1])
                                k++;
                            while(k<l && nums[l]==nums[l+1])
                                l--;

                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {-1,0,-5,-2,-2,-4,0,1,-2}; //-5,-4,-2,-2,-2,-1,0,0,1
    S.printVec_lin(vec);
    S.printVec(S.fourSum(vec,-9));
}



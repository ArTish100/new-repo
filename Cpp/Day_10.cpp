#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s=nums.size();
        vector<int> ret={};
        for(int i=0;i<s-1;i++){
            for(int j=i+1;j<s;j++){
                if(nums[i]+nums[j]==target){
                    ret={i,j};
                    return ret;
                }
                    
            }
        }
        return ret;
    }
};
int main(){
    Solution S;
    vector<int> nums={3,2,3};
    int target=6;
    vector<int> vec=S.twoSum(nums,target);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(),nums.end());
            return funcLowerThanPair(nums,upper+1)-funcLowerThanPair(nums,lower);
        }
        
        long long funcLowerThanPair(vector<int>& nums, int value){
            int l = 0;
            int r = nums.size()-1;
            int count=0;
            int sum;
            while(l<=r){
                sum = nums[l]+nums[r]; 
                if(sum<value){
                    count += (r-l);
                    l++;
                    cout<<count<<endl;
                }else{
                    r--;
                }
            }
            cout<<" one finish "<<endl;
            return count;
        }
};

int main(){
    Solution S;
    vector<int> V = {0,1,7,4,4,5};
    cout<<S.countFairPairs(V,3,6);
}
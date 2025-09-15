#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> uset;
        int nlen = nums.size();
        int max = nums[0];
        for(int j=0;j<nlen;j++){
            if(max<nums[j])
                max = nums[j];
            if(nums[j]>0)
                uset.insert(nums[j]);
        }
        int i=1;
        // cout<<max<<endl;
        for(i;i<=max;i+=1){
            // cout<<i<<endl;
            if(uset.find(i)==uset.end()){
                // cout<<"works "<<i<<endl;
                return i;
            }
        }
        return i;
    }
};

int main(){
    Solution S;
    vector<int> cev = {1,2,0};
    cout<<S.firstMissingPositive(cev);
}

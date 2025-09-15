#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            vector<int> ans;
            for(int i=0;i<nums.size();i++){
                ans.push_back(nums[nums[i]]);
            }
            for(int j=0;j<nums.size();j++){
                cout<<ans[j];
            }
            return ans;
        }
};

int main(){
    Solution S;
    vector<int> V={5,0,1,2,3,4};
    S.buildArray(V);
}
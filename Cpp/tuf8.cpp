//Leaders in an Array

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
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int nlen = nums.size();
        if(nlen == 1)
            return nums;
        int maxelem = nums[nlen-1];
        ans.push_back(maxelem);
        for(int i = nlen-2;i>=0;i--){
            if(nums[i]>maxelem){
                ans.push_back(nums[i]);
                maxelem = nums[i];
            }
        }
        return ans;

    }
};

int main(){
    Solution S;
    vector<int> vec = {10, 22, 12, 3, 0, 6};
    S.printVec(vec);
    S.printVec(S.rearrangeArray(vec));
}

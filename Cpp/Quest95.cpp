#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    void sortColors(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int r = nums.size()-1;
        int temp;
        while(m<=r){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m]==1){
                m++;
            }else{
                swap(nums[r],nums[m]);
                r--;
            }
        }
    }
};

int main(){
    Solution S;
    vector<int> vec = {2,0,1};
    S.printVec(vec);
    S.sortColors(vec);
    S.printVec(vec);
}
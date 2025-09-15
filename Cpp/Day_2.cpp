#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> p = nums;
        cout<<nums[1]<<endl;
        int i = p.size();
        int m=0;
        for(int p = 0 ; p < i ; p++){
            for(int q = p+1 ; q < i ; q++){
               m++; 
            }
        }
        cout<<m<<endl;
    }
};

int main(){
    Solution S;
    vector<int> nums({4,5,0,-2,-3,1});
    int k = S.subarraysDivByK(nums,5);
    cout<<k;
}
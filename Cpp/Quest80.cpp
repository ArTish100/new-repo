#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
    int min(int a, int b){
        if(a>b)
            return b;
        return a;
    }
    public:
        int findMin(vector<int>& nums) {
            int nlen = nums.size();
            int l=0;
            int h=nlen-1;
            int m;
            int min = nums[0];
            while(l<=h){
                if(nums[l]<nums[h]){
                    min = this->min(nums[l],min);
                    break;
                }
                m = l-((l-h)/2);
                if(nums[m]>=nums[h]){
                    l = m+1;
                    min = nums[h];
                }else{
                    h=m-1;
                }
            }
            return min;

        }
    };

int main(){
    Solution S;
    vector<int> V={11,13,15,17};
    cout<<S.findMin(V);
}
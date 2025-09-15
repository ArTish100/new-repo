//Painter's Partition Problem

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public : 
        int maxVal(vector<int> nums){
            int maxi = -1;
            for(auto a : nums){
                maxi = max(maxi,a);
            }
            return maxi;
        }

        int sumVal(vector<int> nums){
            int maxi = 0;
            for(auto a : nums){
                maxi+=a;
            }
            return maxi;
        }

        int calcVal(vector<int> nums, int m){
            int subsum = 0;
            int cnt = 1;
            for(auto a : nums){
                subsum+=a;
                if(subsum>m){
                    subsum = a;
                    cnt++;
                }
            }
            return cnt;
        }

        int paintPart(vector<int> nums, int k){
            int l = maxVal(nums);
            int r = sumVal(nums);
            int m;
            while(l<=r){
                m = l+(r-l)/2;
                int calc = calcVal(nums, m);
                if(calc<=k){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
            return l;
        }
};

int main(){
    Solution S;
    vector<int> vec = {10,20,30,40};
    cout<<S.paintPart(vec,2);
}
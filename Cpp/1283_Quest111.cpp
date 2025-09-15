//1283. Find the Smallest Divisor Given a Threshold

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
    public:
        int maximumVal(vector<int>& piles){
            int maxi = INT_MIN;
            for(int a : piles){
                maxi = max(maxi,a);
            }
            return maxi;
        }
        
        int calcFunc(vector<int>& nums, int m){
            int ret=0;
            for(int a : nums){
                ret+=ceil((double)a/(double)m);
            }
            return ret;
        }

        int smallestDivisor(vector<int>& nums, int threshold) {
            int l = 1;
            int r = maximumVal(nums);
            int m;
            int ans=-1;
            while(l<=r){
                m = l+(r-l)/2;
                int calc = calcFunc(nums,m);
                if(calc<=threshold){
                    ans = m;
                    r=m-1;
                }else{
                    
                    l=m+1;
                    
                }
            }
            return ans;
        }
};


int main(){
    Solution S;
    vector<int> vec = {1,2};
    cout<<S.smallestDivisor(vec,6);
}
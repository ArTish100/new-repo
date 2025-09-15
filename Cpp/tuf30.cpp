//Minimise Maximum Distance between Gas Stations

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

        int findMaxDist(vector<int> nums){
            int maxdist = 0;
            int nlen = nums.size();
            for(int i=1;i<nlen;i++){
                maxdist = max(nums[i]-nums[i-1],maxdist);
            }
            return maxdist;
        }

        int calcVal(vector<int> nums, long double m){
            int div;
            int cnt = 0;
            int nlen = nums.size();
            for(int i=1;i<nlen;i++){
                div = (nums[i]-nums[i-1])/m;
                
                if((div*m)==(nums[i]-nums[i-1])){
                    div--;
                }
                cnt+=div;
            }
            return cnt;
        }

        long double maxDistGas(vector<int> nums, int k){
            long double l = 0;
            long double r = findMaxDist(nums);
            long double m;
            long double lim = 1e-6;
            while(r-l>lim){
                
                m = l+(r-l)/2.0;
                int calc = calcVal(nums, m);
                if(calc>k){
                    l=m;
                }else{
                    r=m;
                }
            }
            return r;
        }
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3,4,5};
    cout<<S.maxDistGas(vec,4);
}
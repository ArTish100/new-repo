//410. Split Array Largest Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
    public:
        int maxVal(vector<int>& piles){
            int maxi = INT_MIN;
            for(int a : piles){
                maxi = max(maxi,a);
            }
            return maxi;
        }
        int sumVal(vector<int>& piles){
            int sums = 0;
            for(int a : piles){
                sums+=a;
            }
            return sums;
        }
        int calcVal(vector<int>& arr, int m){
            int subsum = 0;
            int cnt = 1;
            int maxi = -1;
            for(int a : arr){
                subsum+=a;
                if(subsum>m){
                    subsum = a;
                    cnt++;
                }
            }
            return cnt;
        }
        int splitArray(vector<int>& nums, int k) {
            int l = maxVal(nums);
            int r = sumVal(nums);
            int m;
            int ans = -1;
            while(l<=r){
                m = l+(r-l)/2;
                int calc = calcVal(nums,m);
                if(calc<=k){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
            return l;
        }
};


int main(){
    Solution S;
    vector<int> vec = {1,2,3,4,5};
    cout<<S.splitArray(vec,2);
}
//1011. Capacity To Ship Packages Within D Days

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
    public:
        int sumVal(vector<int>& piles){
            int maxi = 0;
            for(int a : piles){
                maxi+=a;
            }
            return maxi;
        }

        int maximumInVec(vector<int>& piles){
            int maxi = 0;
            for(int a : piles){
                maxi=max(maxi,a);
            }
            return maxi;
        }
        
        int calcFunc(vector<int>& nums, int m){
            int ret=1;
            int temp=0;
            for(int a : nums){
                temp+=a;
                if(temp>m){
                    ret+=1;
                    temp=a;
                }
            }
            return ret;
        }

        int shipWithinDays(vector<int>& weights, int days) {
            int l=maximumInVec(weights);
            int r=sumVal(weights);
            int m;
            int ans=-1;
            while(l<=r){
                m = l+(r-l)/2;
                int calc = calcFunc(weights,m);
                if(calc<=days){
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
    vector<int> vec = {1,2,3,1,1};
    cout<<S.shipWithinDays(vec,4);
}

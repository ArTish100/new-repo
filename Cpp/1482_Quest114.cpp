//1482. Minimum Number of Days to Make m Bouquets

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
        int calcVal(vector<int>& piles, int m, int k, int mid){
            int adj=0;           
            int ans=0; 
            for(int a : piles){
                if(mid>=a){
                    adj+=1;
                }else{
                    adj=0;
                }
                if(adj==k){
                    ans+=1;
                    adj=0;
                }
                    
            }
            return ans;
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            int maxi = maximumVal(bloomDay);
            int l=1;
            int r=maximumVal(bloomDay);
            int ans =-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                int cmp = calcVal(bloomDay,m,k,mid);
                cout<<cmp<<" "<<mid<<endl;
                if(cmp>=m){
                    ans = mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            return ans;
        }
};


int main(){
    Solution S;
    vector<int> vec = {7,7,7,7,12,7,7};
    cout<<S.minDays(vec,2,3);
}
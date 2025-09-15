//Allocate Minimum Number of Pages

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
        int sumVal(vector<int>& arr){
            int sums = 0;
            for(int a : arr){
                sums+=a;
            }
            return sums;
        }
        int calcVal(vector<int>& arr, int mid){
            int count = 0 ;
            int m=1;
            for(int a : arr){
                count+=a;
                if(count>mid){
                    count=a;
                    m++;
                }
            }
            return m;
        }
        int allocMinPage(vector<int>& arr, int n, int m) {
            int l = maxVal(arr);
            int r = sumVal(arr);
            int mid;
            int ans = -1;
            while(l<=r){
                mid = l+(r-l)/2;
                cout<<"m : "<<mid<<endl;
                int calc = calcVal(arr, mid);
                if(calc<=m){
                    if(ans == -1)
                        ans = mid;
                    else{
                        ans = min(ans,mid);
                    }
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
    vector<int> vec = {12, 34, 67, 90};
    cout<<S.allocMinPage(vec,4,2);
}
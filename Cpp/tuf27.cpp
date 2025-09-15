//Aggressive Cows : Detailed Solution

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
        int calcVal(vector<int>& piles, int mid, int num_cows){
            int temp = piles.front();           
            for(int a : piles){
                cout<<a-temp<<endl;
                if(a-temp>=mid){
                    num_cows--;
                    temp = a;
                    cout<<"temp : "<<temp<<endl;
                }
            }
            return num_cows;
        }
        int aggrCow(vector<int>& arr, int n, int k) {
            sort(arr.begin(),arr.end());
            int l=1;
            int r=arr.back()-arr.front();
            if(k==2){
                return r;
            }
            int m;
            int ans;
            while(l<=r){
                m = l+(r-l)/2;
                cout<<"m : "<<m<<endl;
                int calc = calcVal(arr,m,k-1);
                
                if(calc<=0){
                    ans = m;
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            return ans;
        }
};


int main(){
    Solution S;
    vector<int> vec = {4,2,1,3,6};
    cout<<S.aggrCow(vec,5,2);
}
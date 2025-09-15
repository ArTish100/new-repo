//1539. Kth Missing Positive Number

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution{
    public:
        

        int maximumInVec(vector<int>& piles){
            int maxi = 0;
            for(int a : piles){
                maxi=max(maxi,a);
            }
            return maxi;
        }
        
        

        int findKthPositive(vector<int>& arr, int k) {
            int l=0;
            int r=arr.size()-1;
            int m;
            int temp=-1;
            while(l<=r){
                m = l+(r-l)/2;
                temp = arr[m]-m-1;
                if(temp<k){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            return r+k+1;
        }

        int findKthPositive1(vector<int>& arr, int k) {
            int l=1;
            int r=k+maximumInVec(arr);
            unordered_set<int> vec = {arr.begin(),arr.end()};
            int m;
            while(l<=r){
                if(vec.find(l)==vec.end())
                    k--;
                if(k==0)
                    return l;
                l++;
            }
        }
};


int main(){
    Solution S;
    vector<int> vec = {1,2,3,4};
    cout<<S.findKthPositive(vec,2);
}

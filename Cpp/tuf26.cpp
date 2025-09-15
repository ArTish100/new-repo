//875. Koko Eating Bananas

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
    public:
        int calcTot(vector<int>& piles, int m){
            int ans=0;
            for(int a : piles){
                ans+=ceil((double)a/(double)m);
            }
            return ans;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int l=1;
            sort(piles.begin(),piles.end());
            int r = piles[piles.size()-1];
            int ans;
            while(l<=r){
                int m = l+(r-l)/2;
                int trials = calcTot(piles, m);
                cout<<trials<<endl;
                if(trials<=h){
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
    vector<int> vec = {30,11,23,4,20};
    cout<<S.minEatingSpeed(vec,5);
}
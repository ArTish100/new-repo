//Median of Row Wise Sorted Matrix

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
    public:
        int numElemBeforem(vector<int> vec, int m, int r){
            int l = 0;
            int mid;
            int ans=r+1;
            while(l<=r){
                mid = l+(r-l)/2;
                cout<<mid<<" mid "<< endl;
                if(vec[mid]>m){
                    ans = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            return ans;
        }

        int calcVal(vector<vector<int>>vec, int m, int nrows, int ncols){
            int cnt = 0;
            for(int i=0;i<nrows;i++){
                cnt+=numElemBeforem(vec[i], m, ncols-1);
                cout<<cnt<<endl;
            }
            
            return cnt;
        }

        int medianRowWiseSorted(vector<vector<int>> vec){
            int l = INT_MAX;
            int r = INT_MIN;
            int m;
            int nrows = vec.size();
            int ncols = vec[0].size();
            for(int i=0;i<nrows;i++){
                l = min(l,vec[i][0]);
                r = max(r,vec[i][ncols-1]);
            }
            int totNum = (nrows*ncols)/2;
            while(l<=r){
                m = l+(r-l)/2;
                cout<<l<<" "<<r<<" "<<m<<endl;
                int numb = calcVal(vec, m, nrows, ncols);
                
                if(numb<=totNum){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
            return l;
        }
};

int main(){
    Solution S;
    vector<vector<int>> vec = {{1,4,9},{2,5,6},{3,8,7}};
    cout<<S.medianRowWiseSorted(vec);
}
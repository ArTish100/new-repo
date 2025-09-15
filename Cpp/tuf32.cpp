//Find the row with maximum number of 1's

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public :
        int maxNumofOnes(vector<vector<int>>& mat) {
            int ans = -1;
            int nlen = mat.size();
            int r;
            int l;
            int maxcnt = 0;
            int m;
            for(int i=0;i<nlen;i++){
                
                r = mat[0].size()-1;
                l = 0;
                while(l<=r){
                    m = l+(r-l)/2;
                    if(mat[i][m]==1)
                        r = m-1;
                    else
                        l = m+1;
                }
                cout<<mat[0].size()-l<<endl;
                if(mat[0].size()-l>maxcnt){
                    maxcnt = mat[0].size()-l;
                    ans = i;
                }
            }
            return ans;
        }   
};

int main(){
    Solution S;
    vector<vector<int>> mat = {{0},{0}};
    cout<<S.maxNumofOnes(mat);
}

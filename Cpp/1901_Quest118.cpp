//1901. Find a Peak Element II

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public :
        void printVector(vector<int> vec){
            for(int a : vec){
                cout<<a<<" ";
            }
            cout<<endl;
            return;
        }

        int maxVal(vector<vector<int>> mat, int m){
            int maxElem = -1;
            int index = -1;
            int matRows = mat.size();
            for(int i=0;i<matRows;i++){
                if(mat[i][m]>maxElem){
                    maxElem = mat[i][m];
                    index = i;
                }
            }
            return index;
        }

        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int l = 0;
            int colsize = mat[0].size();
            int r = colsize-1;
            int m ;
            int row;
            int left;
            int right;
            while(l<=r){
                m = l+(r-l)/2;
                row = maxVal(mat, m);
                left = m-1>=0 ? mat[row][m-1] : -1;
                right = m+1<colsize ? mat[row][m+1] : -1;
                if(mat[row][m]>left && mat[row][m]>right){
                    cout<<mat[row][m]<<endl;
                    return {row,m};
                }
                    
                else if(mat[row][m]<left)
                    r = m-1;
                else
                    l = m+1;
            }
            return {-1,-1};
        }
};

int main(){
    Solution S;
    vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
    int target = 0;
    S.printVector(S.findPeakGrid(mat));
}


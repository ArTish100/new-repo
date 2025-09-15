//Search in a 2 D matrix

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public :
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int col = matrix[0].size();
            int l=0;
            int r = rows*col-1;
            int m;
            while(l<=r){
                m = l+(r-l)/2;
                int mrow = m/col;
                int mcol = m%col;
                if(matrix[mrow][mcol]==target){
                    return true;
                }else if(matrix[mrow][mcol]>target){
                    r = m-1;
                }else
                    l = m+1;
            }
            return false;
        }
        bool searchMatrix1(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int col = matrix[0].size();
            int l=0;
            int r = rows-1;
            int m;
            while(l<=r){
                m = l+(r-l)/2;
                if(matrix[m][col-1]<target){
                    l = m+1;
                }else if(matrix[m][0]>target){
                    r = m-1;
                }else
                    break;
            }
            if(!(l<=r)){
                return false;
            }
            int k = m;
            l = 0;
            r = col-1;
            while(l<=r){
                m = l+(r-l)/2;
                if(matrix[k][m]==target)
                    return true;
                else if(matrix[k][m]<target)
                    l = m+1;
                else
                    r = m-1;
            }
            return false;
        }   
};

int main(){
    Solution S;
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 60;
    cout<<S.searchMatrix(mat,target);
}

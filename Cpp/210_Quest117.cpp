//240. Search a 2D Matrix II

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public :
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            int row = 0;
            int col = m-1;
            while(row<n && col>=0){
                if(matrix[row][col]==target)
                    return true;
                else if(matrix[row][col]<target)
                    row++;
                else
                    col--;
            }
            return false;
        }
};

int main(){
    Solution S;
    vector<vector<int>> mat = {{-1,-1,-1,-1,4},{1,5,7,11,15},{2,5,8,12,19},{3,5,9,16,22},{4,13,14,17,24},{18,21,23,26,30}};
    int target = 0;
    cout<<S.searchMatrix(mat,target);
}

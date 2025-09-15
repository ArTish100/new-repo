#include<iostream>
#include<vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution {
    public:
        
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int col = matrix[0].size();
            int l=0;
            int r=rows-1;
            int m;
            while(l<=r){
                m=(r+l)/2;
                if(matrix[m][col-1]<target)
                    l=m+1;
                else if(matrix[m][0]>target)
                    r=m-1;
                else
                    break;
            }
            if(!(l<=r))
                return false;
            int k=m;
            l=0;
            r=col-1;
            while(l<=r){
                m=(r+l)/2;
                if(matrix[k][m]<target)
                    l=m+1;
                else if(matrix[k][m]>target)
                    r=m-1;
                else
                    return true;
            }
            return false;
        }
};

int main(){
    Solution S;
    vector<vector<int>> V = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<S.searchMatrix(V,11);
}
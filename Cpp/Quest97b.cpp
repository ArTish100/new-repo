//48. Rotate Image
//Transpose then reverse

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    void printVec(vector<vector<int>> nums){
        for(auto a : nums){
            for(auto b : a)
                cout<<b<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    void rotate(vector<vector<int>>& matrix) {
        int nlen = matrix.size();
        for(int i=0;i<nlen;i++){
            for(int j=i;j<nlen;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i =0;i<nlen;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        

    }

};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> vec = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    S.printVec(vec);
    S.rotate(vec);
    S.printVec(vec);
}
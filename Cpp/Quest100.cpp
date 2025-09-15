/*
560. Pascal's Triangle

*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
    void printVec_lin(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)
            return {{1}};
        vector<int> n_vec;
        vector<vector<int>> ans;
        ans.push_back({{1}});
        ans.push_back({{1,1}});
        if(numRows>2)
            for(int i=1;i<numRows-1;i++){
                n_vec.push_back(1);
                for(int j=1;j<i+1;j++){
                    n_vec.push_back(ans[i][j]+ans[i][j-1]);
                }
                n_vec.push_back(1);
                ans.push_back(n_vec);
                n_vec.clear();
            }
        return ans;

    }


};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<int> vec = {3,1,2,4};
    //S.printVec_lin(vec);
    S.printVec(S.generate(5));
}

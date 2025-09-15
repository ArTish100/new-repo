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
    
    vector<int> retRow(int numRows){
        vector<int> ans;
        long long a;
        for(int i=0;i<=numRows;i++){
            a=1;
            for(int k=0;k<i;k++){
                a = a*(numRows-k);
                a = a/(k+1);
            }
            ans.push_back((int)a);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            ans.push_back(retRow(i));
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

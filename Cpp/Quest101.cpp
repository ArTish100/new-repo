/*
229. Majority Element II

*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    
    vector<int> majorityElement(vector<int>& nums) {
        int nlen = nums.size();
        int k = nlen/3;
        vector<int> vec;
        unordered_map<int,int> n_map;
        for(int i=0;i<nlen;i++){
            n_map[nums[i]]+=1;
        }
        for(auto &it : n_map){
            if(it.second>k){
                vec.push_back(it.first);
            }
        }
        return vec;
    }


};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<int> vec = {3,2,1};
    //S.printVec_lin(vec);
    S.printVec_lin(S.majorityElement(vec));
}

//88. Merge Sorted Array


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution{
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
        
        return;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m+n;
        for(int i=m;i<total;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
        return;
    }

};

int main(){
    Solution S;
    vector<int> vec1 = {1,2,3,0,0,0};
    vector<int> vec2 = {2,5,6};
    S.printVec_lin(vec1);
    S.printVec_lin(vec2);
    S.merge(vec1,vec1.size()-vec2.size(),vec2,vec2.size());
    S.printVec_lin(vec1);
}



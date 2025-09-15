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
        int i = 0;
        
        while(m!=i){
            if(nums2[0]>nums2[1]){
                swap(nums2[0],nums2[1]);
            }
            if(nums1[i]>nums2[0]){
                swap(nums1[i],nums2[0]);
                i++;
            }else{
                i++;
            }
        }
        sort(nums2.begin(),nums2.end());
        return;
    }

};

int main(){
    Solution S;
    vector<int> vec2 = {1, 4, 8, 10};
    vector<int> vec1 = {2,3,9};
    S.printVec_lin(vec1);
    S.printVec_lin(vec2);
    S.merge(vec1,vec1.size(),vec2,vec2.size());
    S.printVec_lin(vec1);
    S.printVec_lin(vec2);
}



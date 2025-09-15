#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
        return;
    }
    void unionVec(vector<int> nums1, vector<int> nums2){
        int a1 = nums1.size();
        int a2 = nums2.size();
        int a=0;
        int b=0;
        vector<int> ans;
        while(a!=a1 && b!=a2){
            if(nums1[a]>nums2[b]){
                ans.push_back(nums2[b]);
                b++;
            }else{
                ans.push_back(nums1[a]);
                a++;
            } 
        }
        if(a==a1){
            while(b!=a2){
                ans.push_back(nums2[b]);
                b++;
            }
        }else if(b==a2){
            while(a!=a1){
                ans.push_back(nums1[a]);
                a++;
            }
        }
        printVec(ans);
        
    }
    
};

int main(){
    Solution S;
    vector<int> vec1 = {0,2};
    vector<int> vec2 = {1,1,1};
    //S.moveZeroes(vec);
    S.printVec(vec1);
    S.printVec(vec2);
    S.unionVec(vec1,vec2);
}
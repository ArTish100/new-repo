/*
229. Majority Element II

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
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
        int count1 = 0;
        int count2 = 0;
        int elem1 = INT_MIN;
        int elem2 = INT_MIN;
        vector<int> ans;
        for(int i : nums){
            if(count1==0 && elem2!= i){
                count1++;
                elem1 = i;
            }else if(count2==0 && elem1!= i){
                count2++;
                elem2 = i;
            }else if(elem1==i){
                count1++;
            }else if(elem2==i){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        int nlen = nums.size();
        count1 = 0;
        count2 = 0;
        for(int i:nums){
            if(i==elem1){
                count1++;
            }
            if(i==elem2){
                count2++;
            }

        }
        int mini = int(nums.size() / 3) + 1;
        if (count1 >= mini) ans.push_back(elem1);
        if (count2 >= mini) ans.push_back(elem2);

        return ans;
    }


};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<int> vec = {2,2,1,3};
    //S.printVec_lin(vec);
    S.printVec_lin(S.majorityElement(vec));
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    // int majorityElement(vector<int>& nums) {
    //     int cmp = nums.size()/2;
    //     unordered_map<int,int> n_map;
    //     for(int a : nums){
    //         n_map[a]++;
    //     }
    //     int max = 0;
    //     int n_m;
    //     for(auto &it : n_map){
    //         if(it.second>max){
    //             max = it.second;
    //             n_m = it.first;
    //         }    
    //     }
    //     return n_m;
        
    // }
    int majorityElement(vector<int>& nums) {
        int cmp = nums.size()/2;
        int elem;
        int count=0;
        for(int a : nums){
            if(count==0){
                count=1;
                elem = a;
            }else if(elem == a){
                count++;
            }else{
                count--;
            }
        }
        return elem;
        return -1;
    }
};

int main(){
    Solution S;
    vector<int> vec = {2,2,1,1,1,2,2};
    S.printVec(vec);
    cout<<S.majorityElement(vec);
    //S.printVec(vec);
}
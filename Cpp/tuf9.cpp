//Leaders in an Array

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution{
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_set<int> n_set(nums.begin(),nums.end());
        int long_elem = 0;
        int length;
        for(int i : n_set){
            if(n_set.find(i-1)==n_set.end()){
                length = 1;
                while(n_set.find(i+length)!=n_set.end())
                    length++;
                long_elem = max(long_elem,length);
            }
        }
    }
};

int main(){
    Solution S;
    vector<int> vec = {10, 22, 12, 3, 0, 6};
    S.printVec(vec);
    S.printVec(S.rearrangeArray(vec));
}



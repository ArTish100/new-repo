//78. Subsets

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printAns(vector<vector<int>> ans){
        for(auto a : ans){
            for(int b : a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int subs = 1<<n;
        for(int i=0; i<subs ; i++){
            vector<int> dstr = {};
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    dstr.push_back(nums[j]);
                }
            }
            ans.push_back(dstr);
        }
        return ans;
    }  
    
};

int main(){
    Solution S;
    vector<vector<int>> ans;
    vector<int> vec = {1,2,3};
    ans = S.subsets(vec);
    S.printAns(ans);
}
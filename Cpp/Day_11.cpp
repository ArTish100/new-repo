#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int s=nums.size();
        vector<vector<int>> ans={};
        for(int i=0;i<s-2;i++){
            for(int j=i+1;j<s-1;j++){
                for(int k=j+1;k<s;k++){
                    if(nums[i]+nums[j]+nums[k]==0)
                        ans.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution S;
    vector<int> vec={0,0,0};
    vector<vector<int>> ans=S.threeSum(vec);
    int s=ans.size();
    cout<<s;
    for(int i=0;i<s;i++)
        for(int j=0;j<3;j++)
            cout<<ans[i][j]<<" ";
    
}
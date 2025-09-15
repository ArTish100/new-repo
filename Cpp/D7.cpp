#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=-1;
        vector<int> curr_sq_streak;
        vector<int> stored_sq_streak;
        for(int i=0;i<nums.size();i++){
            curr_sq_streak.push_back(nums[i]);
            cout<<curr_sq_streak[0]<<endl;
            for(int j=i+1;j<nums.size();j++){
                int k=*(--curr_sq_streak.end());
                cout<<k;
                if(nums[j]==(k)*(k)){
                    cout<<"works";
                    curr_sq_streak.push_back(nums[j]);
                    
                }
            }
            if(curr_sq_streak.size()>stored_sq_streak.size())
                stored_sq_streak=curr_sq_streak;
            curr_sq_streak.clear();
        }
        if(stored_sq_streak.size()>1)
            ans=stored_sq_streak.size();
        return ans;
    }
};
int main(){
    Solution S;
    vector<int> vec = {2,3,5,6,7};
    cout<<S.longestSquareStreak(vec);
}
//Frog Jump with k Distances

#include<iostream>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int tabulation(vector<int> &vec, vector<int> &dp, int jumps, int ind){
        int vlen = vec.size();
        vector<int> dp1(vec.size(), -1);
        dp1[0] = 0;
        int ans;
        int curr;
        for(int i=1;i<vlen;i++){
            ans = INT_MAX;
            for(int j=1;j<=jumps;j++){
                if(i-j>=0){
                    curr = dp1[i-j] + abs(vec[i]-vec[i-j]);
                    ans = min(ans, curr);
                }
                dp1[i] = ans;
            }
        }
        return dp1[vlen-1];
    }
    int memoizWay(vector<int> &vec, vector<int> &dp, int jumps, int ind){
        if(ind<=0)  
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int cmp = INT_MAX;
        int curr;
        for(int i=1;i<=jumps;i++){
            if(ind-i >= 0){
                curr = memoizWay(vec, dp, jumps, ind-i)+abs(vec[ind]-vec[ind-i]);
                cmp = min(cmp,curr);
            }
        }
        return dp[ind] = cmp;
    }
    int recurWay(vector<int> &vec, int jumps, int ind){
        if(ind<=0)
            return 0;
        int ans = INT_MAX;
        int jump;
        for(int i=1;i<=jumps;i++){
            if(ind-i>=0){
                jump = recurWay(vec, jumps, ind-i) + abs(vec[ind]-vec[ind-i]);
                ans = min(ans, jump);
            }
        }
        return ans;
    }
    void frogJump(vector<int> vec, int jumps){
        vector<int> dp(vec.size(), -1);
        cout<<recurWay(vec, jumps, vec.size()-1)<<endl;
        cout<<memoizWay(vec, dp, jumps, vec.size()-1)<<endl;
        cout<<tabulation(vec, dp, jumps, vec.size()-1)<<endl;
    }
};

int main(){
    Solution S;
    vector<int> vec = {30, 10, 60, 10, 60, 50};
    S.frogJump(vec,3);
}
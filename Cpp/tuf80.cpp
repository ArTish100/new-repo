//Frog Jump

#include<iostream>
#include<string>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int recurWay(vector<int>& height, int ind){
        if(ind == 0)
            return 0;
        if(ind>=1){
            int jone = recurWay(height, ind-1) + abs(height[ind-1]-height[ind]);
            int jtwo = recurWay(height, ind-2) + abs(height[ind-2]-height[ind]);
            return min(jone,jtwo);
        }
    }
    int recurWay1(vector<int>& height, vector<int>& dp, int ind){
        if(ind == 0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int jtwo = INT_MAX;
        int jone = recurWay(height, ind-1) + abs(height[ind-1]-height[ind]);
        if(ind>1)
            jtwo = recurWay(height, ind-2) + abs(height[ind-2]-height[ind]);
        return dp[ind] = min(jone,jtwo);
        
    }
    int minCost(vector<int>& height) {
        int hsize = height.size();
        vector<int> vec1(hsize+1,-1);
        cout<< recurWay(height, hsize-1)<<endl;
        cout<< recurWay1(height, vec1 ,hsize-1)<<endl;
        vector<int> ans(hsize,-1);
        ans[0] = 0;
        for(int i=1;i<hsize;i++){
            int jtwo = INT_MAX;
            int jone = ans[i-1] + abs(height[i-1]-height[i]);
            if(i>1)
                jtwo = ans[i-2] + abs(height[i-2]-height[i]);
            ans[i] = min(jtwo,jone);
        }
        cout<<ans[hsize-1]<<endl;
        int prev1 = 0;
        int prev2 = 0;
        int curr;
        for(int i=1;i<hsize;i++){
            int jtwo = INT_MAX;
            int jone = prev1 + abs(height[i-1]-height[i]);
            if(i>1)
                jtwo = prev2 + abs(height[i-2]-height[i]);
            curr = min(jone,jtwo);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(){
    Solution S;
    vector<int> vec = {20, 30, 40, 20};
    cout<<S.minCost(vec);
}
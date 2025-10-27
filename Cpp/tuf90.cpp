//Maximum Profit in Job Scheduling/Weighted Job Scheduling

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

class Solution {
  public:
    int memoization(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
    }

    int recurWay(vector<vector<int>> jobs) {
        
    }
    bool nooverlap(int i, int j, vector<vector<int>> jobs){
        if(jobs[j][0]<=jobs[i][1])
            return true;
        return false;
    }
    void dpAllWays(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> jobs(n);
        for(int i=0;i<n;i++)
            jobs[i]={endTime[i],startTime[i],profit[i]};
        sort(jobs.begin(),jobs.end());
        // for(auto i:jobs){
        //     for(int j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        vector<int> dp(n,0);
            
        for(int i=0;i<n;i++){
            dp[i]=jobs[i][2];
            for(int j=0;j<i;j++){
                if(nooverlap(i,j,jobs)){
                    dp[i]=max(dp[i],jobs[i][2]+dp[j]);
                }
            }
        }
        int maxi=INT_MIN;
        for(int i:dp)
            maxi=max(maxi,i);
        cout<<maxi<<endl;
    }
  
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
    }
};

int main(){
    vector<int> startTime = {1, 2, 3, 3}; vector<int> endTime  = {3, 4, 5, 6} ; vector<int> profit  = {50, 10, 40, 70};
    // vector<int> startTime = {1, 2, 3, 4, 6}; vector<int> endTime  = {3, 5, 10, 6, 9} ; vector<int> profit  = {20, 20, 100, 70, 60};
    
    Solution S;
    S.dpAllWays(startTime, endTime, profit);
    // cout<<S.jobScheduling(startTime, endTime, profit)<<endl;

}
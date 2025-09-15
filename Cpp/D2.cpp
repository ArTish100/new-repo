#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> sep_num;  
        int n=nums.size();
        cout<<n;
        int left,right = nums[0][0];
        priority_queue<int, vector<vector<int>>, greater<int>> pq;
        for(int i=0;i<n;i++){
            sep_num = nums[i];
            left = min(left,sep_num[0]);
            right = max(right,sep_num[0]);
            pq.push({sep_num[0], i, 0});
        }
        vector<int> ans;
        ans.push_back(left);
        ans.push_back(right);
        while(true){
            int u, v, w;
            u, v, w = pq.top()[0], pq.top()[1], pq.top()[2];
            pq.pop();
            w+=1;
            if (w==nums[v].size())
                return ans;
            pq.push({nums[v][w], v, w});
            left = min(left, pq.top()[0]);
            right = max(right, nums[v][w]);
            if(right-left < ans[1]-ans[0])
                ans={left,right};
        }


        return ans;
    }
};

int main(){
    Solution S;
    vector<vector<int>> intervals={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> ans = S.smallestRange(intervals);
    std::cout<<ans[0]<<endl;
    std::cout<<ans[1]<<endl;
}
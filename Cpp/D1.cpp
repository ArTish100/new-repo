#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(auto r : intervals){
            cout<<r[0]<<" "<<r[1]<<endl;
        }
        cout<<endl;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& e : intervals) {
            if (q.size() && q.top() < e[0]) {
                q.pop();
            }
            cout<<e[1]<<" ";
            q.push(e[1]);
        }
        int qlen = q.size();
        for(int i=0;i<qlen;i++){
            cout<<q.top()<<" ";
            q.pop();
        }
        return q.size();
    }
};

int main(){
    Solution S;
    vector<vector<int>> intervals={{5,10},{6,8},{1,5},{2,3},{1,10}};
    int ans = S.minGroups(intervals);
    cout<<ans;
}
//Rat in a Maze

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printVec(vector<vector<string>> vec){
        for(auto a : vec){
            for(string b : a){
                cout<<b<<endl;
            }
            cout<<endl;
        }
    }
    void printVecLin(vector<string> vec){
        for(auto b : vec){
                cout<<b<<" ";
        }
        cout<<endl;
    }
    void dfs(vector<string> &ans, string &dstr, vector<vector<int>> &grid, int i, int j, int n){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==-1 || grid[i][j]==0)
            return;
        if(i==n-1 && j==n-1){
            if(grid[n-1][n-1]==1)
                ans.push_back(dstr);
            return;
        }
        int og = grid[i][j];
        grid[i][j] = -1;
        dstr.push_back('D');
        dfs(ans, dstr, grid, i+1, j, n);
        dstr.pop_back();
        dstr.push_back('L');
        dfs(ans, dstr, grid, i, j-1, n);
        dstr.pop_back();
        dstr.push_back('R');
        dfs(ans, dstr, grid, i, j+1, n);
        dstr.pop_back();
        dstr.push_back('U');
        dfs(ans, dstr, grid, i-1, j, n);
        dstr.pop_back();
        grid[i][j] = og;
        return;
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        vector<string> ans;
        string dstr;
        int n = grid.size();
        dfs(ans, dstr, grid, 0, 0, n);
        return ans;
    }
};

int main(){
    Solution S;
    vector<string> ans;
    vector<vector<int>> grid = {{1,1,1},{1,0,1},{1,1,1}};
    ans = S.findPath(grid);
    S.printVecLin(ans);
}
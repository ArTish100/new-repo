//Connected Components in an Undirected Graph

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

class Solution {
  public:
    vector<vector<int>> createGraph(int V, vector<vector<int>>& edges){
        vector<vector<int>> grp(V);
        for(vector<int> i : edges){
            grp[i[0]].push_back(i[1]);
            grp[i[1]].push_back(i[0]);
        }
        return grp;
    }

    void dfs(int i, vector<int> &visited, vector<vector<int>> &grp, vector<int> &dstr){
        dstr.push_back(i);
        visited[i]=1;
        for(int a:grp[i]){
            if(!visited[a])
                dfs(a, visited, grp, dstr);
        }
        return;
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges){
        vector<vector<int>> grp = createGraph(V, edges);
        vector<int> visited(V,0);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int> dstr;
                dfs(i, visited, grp, dstr);
                ans.push_back(dstr);
            }
        }
        for(vector<int> vec: ans){
            for(int i:vec)
                cout<<i<<" ";
            cout<<endl;
        }
        return ans;
    }
};

int main(){
    Solution S;
    
    int V=5; vector<vector<int>> edges = {{0, 1}, {2, 1}, {3, 4}};
    // int v=5; vector<vector<int>> edges = {{0, 1}, {6, 0}, {2, 4}, {2, 3}, {3, 4}};
    
    S.getComponents(V, edges);
}
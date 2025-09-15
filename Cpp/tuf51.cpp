//M - Coloring Problem

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printVec(vector<vector<int>> vec){
        for(int i=0;i<vec.size();i++){
            cout<<i<<": ";
            for(int a : vec[i])
                cout<<a<<" ";
            cout<<endl;
        }
    }
    void printVecLin(vector<string> vec){
        for(auto b : vec){
                cout<<b<<" ";
        }
        cout<<endl;
    }
    bool canPaint(vector<int> &list, unordered_map<int,int> &uedge, int color){
        for(int a : list){
            if(color==uedge[a]){
                return false;
            }
        }
        return true;
    }
    bool dfs(int v, vector<vector<int>> &adj_list, int m, unordered_map<int,int> &uedge, int node){
        if(node==v)
            return true;
        for(int i=1;i<=m;i++){
            if(canPaint(adj_list[node], uedge, i)){
                uedge[node] = i;
                if(dfs(v, adj_list, m, uedge, node+1))
                    return true;
                uedge[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj_list(v);
        for(vector<int> a : edges ){
            adj_list[a[0]].push_back(a[1]);
            adj_list[a[1]].push_back(a[0]);
        }
        unordered_map<int,int> uedge;
        for(int i=0;i<v;i++)
            uedge[i] = 0;
        return dfs(v, adj_list, m, uedge, 0);
    }
};

int main(){
    Solution S;
    int V = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    int m = 3;
    cout<<S.graphColoring(V, edges ,m);
}
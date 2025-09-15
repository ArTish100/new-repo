//51. N-Queens

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
    bool applyQueen(vector<string> &dstr, int i, int j, int &n){
        for(int a=0;a<n;a++)
            if(dstr[a][j] == 'Q')
                return false;
        for(int b=0;b<n;b++)
            if(dstr[i][b] == 'Q')
                return false;
        int a=i,b=j;
        while(a>=0 && b>=0){
            if(dstr[a][b] == 'Q')
                return false;
            a--;
            b--;
        }
        a=i,b=j;
        while(a<n && b<n){
            if(dstr[a][b] == 'Q')
                return false;
            a++;
            b++;
        } 
        a=i,b=j;
        while(a<n && b>=0){
            if(dstr[a][b] == 'Q')
                return false;
            a++;
            b--;
        }
        a=i,b=j;
        while(a>=0 && b<n){
            if(dstr[a][b] == 'Q')
                return false;
            a--;
            b++;
        }           
        return true;
    }
    void dfsFunction(vector<vector<string>>&ans, vector<string> dstr, int &n, int nplaced){
        if(nplaced==n){
            ans.push_back(dstr);
            return;
        }
        for(int i=0;i<n;i++){
            if(applyQueen(dstr,nplaced,i,n)){
                dstr[nplaced][i]='Q';
                dfsFunction(ans, dstr, n, nplaced+1);
                dstr[nplaced][i]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> dstr;
        string temp(n,'.');
        for(int i=0;i<n;i++){
            dstr.push_back(temp);
        }
        dfsFunction(ans, dstr, n, 0);
        return ans;
    }
};

int main(){
    Solution S;
    vector<vector<string>> ans;
    ans = S.solveNQueens(9);
    S.printVec(ans);
}
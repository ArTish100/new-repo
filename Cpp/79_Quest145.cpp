//79. Word Search

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
                cout<<b<<" ";
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
    bool dfsFunction(vector<vector<char>> &board,int ind, string word, int i, int j, int m, int n){
        if(ind>=word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[ind] ||board[i][j] == '!')
            return false;
        
        char c = board[i][j];
        board[i][j] = '!';
        
        bool down = dfsFunction(board, ind+1, word, i+1,j,m,n);
        bool up = dfsFunction(board, ind+1, word, i-1,j,m,n);
        bool right = dfsFunction(board, ind+1, word, i,j+1,m,n);
        bool left = dfsFunction(board, ind+1, word, i,j-1,m,n);
        board[i][j] = c;

        return down||up||right||left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())
            return true;
        string dstr;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(dfsFunction(board, 0, word, i,j,m,n))
                        return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution S;
    vector<vector<char>> ans = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<S.exist(ans, "ABCCED");
    //S.printVec(ans);
}
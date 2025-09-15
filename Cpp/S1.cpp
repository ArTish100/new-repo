#include<iostream>
using namespace std;
#include<unordered_map>
#include<set>
#include<vector>

class Solution {
public:
    bool isValidSudoku(vector<vector<string>>& board) {
        unordered_map<string,set<vector<int>>> mp_num;
        vector<int> vec;
        for(int i=0;i<9;i++){
            vec.push_back(i);
            for(int j=0;j<9;j++){
                if(board[i][j]==".")
                    continue;
                vec.push_back(j);
                mp_num[board[i][j]].insert(vec);
                for(auto k : mp_num){
                    if(k.first==board[i][j]){
                        for(auto l : k.second){
                            
                        }
                    }
                }
                vec.pop_back();
            }
            vec.pop_back();
        }
        return true;
    }
};
int main(){
    vector<vector<string>>board {{"8","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    Solution S;
    cout<<S.isValidSudoku(board);
}
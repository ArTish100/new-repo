//54. Spiral Matrix


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    void printVec(vector<vector<int>> nums){
        for(auto a : nums){
            for(auto b : a)
                cout<<b<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    void printVec_lin(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int a = 0;
        int b = m-1;
        int c = 0;
        int d = n-1;
        int dir = 0;
        while(m!=0 && n!=0){
            dir = dir%4;
            if(dir==0){
                for(int i=c;i<=d;i++){
                    ans.push_back(matrix[a][i]);
                    
                }
                a++;
                dir++;
                m--;
            }else if(dir==1){
                for(int i=a;i<=b;i++){
                    ans.push_back(matrix[i][d]);
                }
                d--;
                dir++;
                n--;
            }else if(dir==2){
                for(int i=d;i>=c;i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
                dir++;
                m--;
            }else if(dir==3){
                for(int i=b;i>=a;i--){
                    ans.push_back(matrix[i][c]);
                }
                c++;
                dir++;
                n--;
            }
            else
                break;
        }
        return ans;
    }

};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
    S.printVec(vec);
    S.printVec_lin(S.spiralOrder(vec));
}

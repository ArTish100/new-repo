//73. Set Matrix Zeroes

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
    void setZeroes(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int col=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]==0){
                    nums[i][0] = 0;
                    if(j!=0){
                        nums[0][j] = 0;
                    }else{
                        col = 1;
                    }
                        
                }
                
            }
        }
        cout<<col<<endl;
        printVec(nums);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(nums[i][j]!=0){
                    if(nums[i][0]==0 || nums[0][j]==0){
                        nums[i][j]=0;
                    }
                        
                }
            }
        }
        printVec(nums);
        if(nums[0][0]==0){
            for(int j=0;j<n;j++){
                nums[0][j] = 0;
            }
        }
        printVec(nums);
        if(col){
            for(int i=0;i<m;i++){
                nums[i][0] = 0;
            }
            
        }
        printVec(nums);
          
    }

};


int main(){
    Solution S;
    //vector<vector<int>> vec = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> vec = {{1,0,3}};
    S.printVec(vec);
    S.setZeroes(vec);
    S.printVec(vec);
}
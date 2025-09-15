#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }

    void recurApp(vector<int> k, int l, int r, int klen, int sum, int& subsum){
        if(r==klen){
            return;
        }
        else if(l>r){
            recurApp(k,0,r+1,klen,sum,subsum);
        }else{
            int a=0;
            int itr = 0;
            cout<<"l "<<l<<endl;
            cout<<"r "<<r<<endl;
            for(int i = l;i<=r;i++){
                cout<<"k[i] "<<k[i]<<endl;
                a+=k[i];
                itr++;
            }
            cout<<"a "<<a<<endl;
            cout<<"itr "<<itr<<endl;
            if(a==sum && subsum<itr){
                subsum = itr;
                cout<<a<<" "<<itr<<endl;
            }
                
            recurApp(k,l+1,r,klen,sum,subsum);
        }
    }

    void longSubArr(vector<int> nums, int sum) {
        int nlen = nums.size();
        int subsum=0;
        recurApp(nums,0,0,nlen,sum,subsum);
        cout<<subsum;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {-1, 1, 1};
    //S.moveZeroes(vec);
    S.printVec(vec);
    int sum = 1;
    S.longSubArr(vec,sum);
}
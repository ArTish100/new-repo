#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

class Solution {
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }

    int max(int a , int b){
        if(a>b)
            return a;
        return b;
    }

    void longSubArr(vector<int> nums, int k) {
        int nlen = nums.size();
        map <int,int> n_map;
        int sum = 0;
        int maxlen = 0;
        for(int i=0;i<nlen;i++){
            sum+=nums[i];
            if(sum == k)
                maxlen = max(maxlen,i+1);
            if(n_map.find(sum-k)!=n_map.end()){
                maxlen = max(i-n_map[sum-k],maxlen);
            }
            if(n_map.find(sum)==n_map.end()){
                n_map[sum] = i;
            }
        }
        cout<<maxlen;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {-1,1,1};
    //S.moveZeroes(vec);
    S.printVec(vec);
    int sum = 1;
    S.longSubArr(vec,sum);
}
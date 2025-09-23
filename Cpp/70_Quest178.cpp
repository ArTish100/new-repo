//70. Climbing Stairs

#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
    }
    int fibrecur(int n, vector<int> &vec){
        if(n<=1)
            return n;
        if(vec[n]!=-1)
            return vec[n];
        return vec[n] = fibrecur(n-1, vec) + fibrecur(n-2, vec);
    }
    int fibonacci1(int n) {
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        return fibonacci(n-1)+fibonacci(n-2);
    }
    int fibonacci(int n) {
        vector<int> vec(n+1,-1);
        return fibrecur(n, vec);
    }
    int climbStairs(int n) {
        vector<int> vec(n+1,-1);
        return fibrecur(n, vec);
    }
    
};

int main(){
    Solution S;
    cout<<S.fibonacci(11);
    cout<<S.climbStairs(1);
}
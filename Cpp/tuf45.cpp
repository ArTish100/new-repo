//Reverse a stack using recursion

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    stack<int> s;
    void createStack(vector <int> vec, stack<int> &St){
        for(int v : vec){
            St.push(v);
        }
    }
    void printStack(stack<int> s){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    void revElem(stack<int> &St, int val){
        if(St.empty()){
            St.push(val);
            return;
        }
        int kem = St.top();
        St.pop();
        revElem(St, val);
        St.push(kem);
    }

    void Reverse(stack<int> &St) {
        if(St.empty())
            return;
        int val = St.top();
        St.pop();
        Reverse(St);
        revElem(St,val);
    }
};

int main(){
    Solution S;
    vector<int> vec ={3,2,1,7,6};
    stack<int> st;
    S.createStack(vec, st);
    S.Reverse(st);
    S.printStack(st);
}
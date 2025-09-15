//	Sort a stack using recursion


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
    void createStack(vector <int> vec){
        for(int v : vec){
            s.push(v);
        }
    }
    void printStack(){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    void sortValElem(int val){
        if(s.empty() || s.top()<val){
            s.push(val);
            return;
        }
        int top_val = s.top();
        s.pop();
        sortValElem(val);
        s.push(top_val);
    }

    void sort(){
        if(s.empty())
            return;
        int val = s.top();
        s.pop();
        sort();
        sortValElem(val);
    }
};

int main(){
    Solution S;
    vector<int> vec ={11,2,32,3,41};
    S.createStack(vec);
    S.sort();
    S.printStack();
}
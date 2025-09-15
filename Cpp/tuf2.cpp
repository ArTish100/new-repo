#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
    public:
        int someSol(vector<int> a){
            int k1 = INT_MIN;
            int k2 = INT_MIN;
            for(int b : a){
                if(k1<=b){
                    k2 = k1;
                    k1 = b;
                }
            }
            cout<<k1<<" "<<k2;
        }
};

int main(){
    vector<int> vec = {1,87,46,42,7,90,1,2,90};
    Solution S;
    S.someSol(vec);

}
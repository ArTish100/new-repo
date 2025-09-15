#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
    public:
        int someSol(vector<int> a){
            int k = INT_MIN;
            for(int b : a){
                if(k<b){
                    k = b;
                }
            }
            return k;
        }
};

int main(){
    vector<int> vec = {1,46,42,7,87,90};
    Solution S;
    cout<<S.someSol(vec);

}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int tlen = numbers.size();
            int l = 0;
            int r = tlen - 1;
            while(l<r){
                if(numbers[l]+numbers[r] == target)
                    return {l,r};
                else if(numbers[l]+numbers[r] < target)
                    l++;
                else if(numbers[l]+numbers[r] > target)
                    r--;
            }
        }
};

int main(){
    Solution S;
    vector<int> V={-1,0};
    vector<int> s = S.twoSum(V,-1);
    cout<<s[0]<<s[1];
}
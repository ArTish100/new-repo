//152. Maximum Product Subarray

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
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
        
        return;
    }

    int maxProduct(vector<int>& nums) {
        int prod1 = nums[0];
        int prod2 = nums[0];
        int temp;
        int ans = nums[0];
        int nlen = nums.size();
        for(int i=1;i<nlen;i++){
            temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
            prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
            prod1 = temp;
            ans = max(ans,prod1);
        }
        return ans;
    }

    int maxProduct1(vector<int>& nums) {
        int ans = INT_MIN;
        int pref = 1;
        int suff = 1;
        int nlen = nums.size();
        for(int i=0;i<nlen;i++){
            if(pref==0)
                pref=1;
            if(suff==0)
                suff=1;
            pref*=nums[i];
            suff*=nums[nlen-i-1];
            ans = max(ans,max(pref,suff));
        }
        
    }

};

int main(){
    Solution S;
    vector<int> vec1 = {-2};
    S.printVec_lin(vec1);
    cout<<S.maxProduct(vec1);
}




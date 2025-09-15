#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int min(int a, int b){
        if(a>b)
            return b;
        return a;
    }
    public:
        
        int maxArea(vector<int>& height) {
            int hlen = height.size();
            int j = hlen-1;
            int i = 0;
            int sum = 0;
            int k;
            int nsum;
            while(i<j){
                k = min(height[i],height[j]);
                nsum = (j-i)*k;
                if(nsum>sum){
                    sum = nsum;
                    cout<<k<<endl;
                    cout<<i<<" "<<j<<endl;
                }
                    
                if(height[i+1]>height[i] && k==height[i])
                    i++;
                else
                    j--;
            }
            
            return sum;
            
        }
};
int main(){
    Solution S;
    vector<int> V = {1,1};
    cout<<S.maxArea(V);
}

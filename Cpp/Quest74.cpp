#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int i = 0;
            int j;
            int hlen = height.size();
            while(height[i]==0)
                i++;
            int water=0;
            int elev;
            for(i ; i < hlen ; i++){
                j=i+1;
                elev=0;
                while(height[j]<=height[i] && j<hlen){
                    elev+=height[j];
                    j++;
                }
                cout<<elev<<endl;
                if(j==hlen)
                    j--;
                cout<<j<<endl;
                if(height[j]>=height[i]){
                    water-=elev;
                    water+=(j-i-1)*min(height[i],height[j]);
                }
                cout<<height[j]<<" "<<height[i]<<endl;
                if(j!=hlen-1)
                    i=j-1;

                cout<<water<<endl;
                
            }
            return water;
        }
};

int main(){
    Solution S;
    vector<int> V = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<S.trap(V);
}
//121. Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void printVec(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int nlen = nums.size();
        int l = 0;
        int r;
        int temp;
        int kemp;
        while(l<nlen){
            r=l+1;
            if(l==0){
                if(nums[0]<0){
                    while(nums[r]<0)
                        r++;
                    temp = nums[0];
                    nums[0] = nums[r];
                    for(int i=r;i>l+1;i--){
                        nums[i] = nums[i-1];
                    }
                    nums[1] = temp;
                    cout<<"1"<<endl;
                    printVec(nums);
                }
                l++;
            }else if(nums[l-1]>0 && nums[l]>0){
                while(nums[r]>0)
                    r++;
                temp = nums[l];
                nums[l] = nums[r];
                for(int i=r;i>l+1;i--){
                    nums[i] = nums[i-1];
                }
                nums[l+1] = temp;
                l++;
                cout<<"2"<<endl;
                printVec(nums);
            }else if(nums[l-1]<0 && nums[l]<0){
                while(nums[r]<0)
                    r++;
                temp = nums[l];
                nums[l] = nums[r];
                for(int i=r;i>l+1;i--){
                    nums[i] = nums[i-1];
                }
                nums[l+1] = temp;
                l++;
                cout<<"3"<<endl;
                printVec(nums);
            }else{
                l++;
                cout<<"4"<<endl;
                printVec(nums);
            }
            
        }
        return nums;
    }
};

int main(){
    Solution S;
    vector<int> vec = {-1,1};
    S.printVec(vec);
    S.printVec(S.rearrangeArray(vec));
}

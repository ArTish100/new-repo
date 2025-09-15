//Count inversions in an array
//merge sort method
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

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

    int merge(vector<int>& nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;
        vector<int> vec1(n1);
        vector<int> vec2(n2);
        int count=0;
        for(int a=0;a<n1;a++){
            vec1[a] = nums[left+a];
        }
        for(int a=0;a<n2;a++){
            vec2[a] = nums[mid+1+a];
        }
        int i=0;
        int j=0;
        int k= left;
        while(i<n1 && j<n2){
            if(vec1[i]<=vec2[j]){
                nums[k] = vec1[i];
                i++;
            }else{
                nums[k] = vec2[j];
                count+=n1-i;
                j++;
            }
            k++;
        }
        while (i < n1) {
            nums[k] = vec1[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], 
        // if there are any
        while (j < n2) {
            nums[k] = vec2[j];
            j++;
            k++;
        }
        return count;

    }

    int mergeSort(vector<int>& nums, int left, int right) {
        int count=0;
        if(left>=right)
            return count;
        int mid = left+(right-left)/2;
        count+=mergeSort(nums,left,mid);
        count+=mergeSort(nums,mid+1,right);
        count+=merge(nums,left,mid,right);
        return count;
    }

    void mergeSortMethod(vector<int>& nums) {
        int nlen = nums.size();
        cout<<mergeSort(nums,0,nlen-1);
        
    }

};

int main(){
    Solution S;
    vector<int> vec1 = {5,4,3,2,1};
    S.printVec_lin(vec1);
    S.mergeSortMethod(vec1);
    S.printVec_lin(vec1);
}




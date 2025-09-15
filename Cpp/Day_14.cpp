#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int positionOnMoving(char dir){

    }
    // Function to heapify a subtree rooted with node i, which is an index in arr[]
    void heapify(vector<int>& arr, int n, int i, vector<int>& hp, string& dir) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // Left child index
        int right = 2 * i + 2; // Right child index

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            swap(hp[i], hp[largest]);
            swap(dir[i], dir[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest, hp, dir);
        }
    }

    // Main function to perform heap sort
    void heapSort(vector<int>& arr, vector<int>& hp, string& dir) {
        int n = arr.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, hp, dir);

        // One by one extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);
            swap(hp[0], hp[i]);
            swap(dir[0], dir[i]);

            // Call max heapify on the reduced heap
            heapify(arr, i, 0, hp, dir);
        }
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        heapSort(positions, healths, directions);
        int slen=directions.length();
        char curr=directions[0];
        int same=0;
        int countofbot=slen;
        while(countofbot>1 && same==0){
            countofbot=0;
            for(int i=0;i<directions.length()-1;i++){
                if(positions[i]!=INT_MIN){
                    if(directions[i]=='R'){
                        positions[i]++;
                        if(i>0){
                            if(positions[i]==positions[i-1]){
                                if(healths[i]>healths[i-1]){
                                    healths[i-1]=0;
                                    positions[i-1]=INT_MIN;

                                }else if(healths[i]<healths[i-1]){
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }else{
                                    healths[i-1]=0;
                                    positions[i-1]=INT_MIN;
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }
                            }
                        }else if(i>=0){
                            if(positions[i]==positions[i+1]){
                                if(healths[i]>healths[i+1]){
                                    healths[i+1]=0;
                                    positions[i+1]=INT_MIN;

                                }else if(healths[i]<healths[i+1]){
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }else{
                                    healths[i+1]=0;
                                    positions[i+1]=INT_MIN;
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }
                            }
                        }
                    }else if(directions[i]=='L'){
                        positions[i]--;
                        if(i>0){
                            if(positions[i]==positions[i-1]){
                                if(healths[i]>healths[i-1]){
                                    healths[i-1]=0;
                                    positions[i-1]=INT_MIN;

                                }else if(healths[i]<healths[i-1]){
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }else{
                                    healths[i-1]=0;
                                    positions[i-1]=INT_MIN;
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }
                            }
                        }else if(i>=0){
                            if(positions[i]==positions[i+1]){
                                if(healths[i]>healths[i+1]){
                                    healths[i+1]=0;
                                    positions[i+1]=INT_MIN;

                                }else if(healths[i]<healths[i+1]){
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }else{
                                    healths[i+1]=0;
                                    positions[i+1]=INT_MIN;
                                    healths[i]=0;
                                    positions[i]=INT_MIN;
                                }
                            }
                        }
                    }
                }else{
                    continue;
                }
            }
        }
        for(int i=0;i<slen;i++){
            if (curr!=directions[i]){

            }
        }
    }
};
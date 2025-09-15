#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool check_try1(int arr[2], vector<vector<int>>& obstacles, int dir, int i){
        int old[2];
         old[0] = arr[0];
         old[1] = arr[1];
        for(auto k : obstacles){
            arr[0] = old[0];
            arr[1] = old[1];
            cout<<"works1"<<endl;
            if(dir==0){
                cout<<"works2"<<endl;
                for(int j=1;j<=i;j++){
                    arr[1]+=1;
                    cout<<"works3 :"<<arr[1]<<endl;
                    if(k[0]==arr[1] && k[1]==arr[0]){
                        arr[1]-=1;
                        return false;
                    }
                }
            }else if(dir==180){
                for(int j=1;j<=i;j++){
                    arr[1]-=1;
                    if(k[0]==arr[1] && k[1]==arr[0]){
                        arr[1]+=1;
                        return false;
                    }
                }
            }else if(dir==270){
                for(int j=1;j<=i;j++){   
                    arr[0]-=1;
                    if(k[0]==arr[1] && k[1]==arr[0]){
                        arr[0]+=1;
                        return false;
                    }
                }
            }else if(dir==90){
                for(int j=1;j<=i;j++){
                    arr[0]+=1;
                    if(k[0]==arr[1] && k[1]==arr[0]){
                        arr[0]-=1;
                        return false;
                    }
                }
            }
                
        }
        return true;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir = 90;
        // unordered_map<int,int> dis_dir_mp;
        int arr[2] = {0,0};
        int max[2] = {0,0};
        int try1[2];
        for(auto i : commands){
            try1[0] = arr[0];
            try1[1] = arr[1];
            // dis_dir_mp[90] = 0;
            // dis_dir_mp[180] = 0;
            // dis_dir_mp[270] = 0;
            // dis_dir_mp[0] = 0;
            if(i==-1){
                if(dir==0)
                    dir = 270;
                else
                    dir = abs(dir-90)%360;
            }else if(i==-2){
                dir = abs(dir+90)%360;
            }else{
                // dis_dir_mp[dir]+=i;
                cout<<arr[0]<<":"<<arr[1]<<endl;
                if(dir==0 && check_try1(arr, obstacles, dir, i)){
                    cout<<arr[1]<<endl;
                    if(obstacles.empty())
                        arr[1]+=i;
                    
                }else if(dir==180 && check_try1(arr, obstacles, dir, i)){
                    if(obstacles.empty())
                        arr[1]-=i;
                    cout<<arr[1]<<endl;
                }else if(dir==270 && check_try1(arr, obstacles, dir, i)){
                    if(obstacles.empty())
                        arr[0]-=i;
                    cout<<arr[0]<<endl;
                }else if(dir==90 && check_try1(arr, obstacles, dir, i)){
                    if(obstacles.empty())
                        arr[0]+=i;
                    cout<<arr[0]<<endl;
                }
                cout<<arr[0]<<" "<<arr[1]<<endl;
                if(max[0]*max[0]+max[1]*max[1] < arr[0]*arr[0]+arr[1]*arr[1]){
                    max[0] = arr[0];
                    max[1] = arr[1];
                }
                
            }
            
            
            
        }
        return max[0]*max[0]+max[1]*max[1];
    }
};
int main(){
    Solution S;
    vector<int> vce = {-2,-1,8,9,6};
    vector<vector<int>> obstacles = {{-1,3},{0,1},{-1,5},{-2,-4},{5,4},{-2,-3},{5,-1},{1,-1},{5,5},{5,2}};
    cout<<S.robotSim(vce, obstacles);
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> try_mp;
    vector<int> try_vec={3,2,6,1};
    try_mp[1]=12;
    try_mp[6]=45;
    try_mp[3]=10;
    try_mp[2]=11;
    vector<int> ans;
    for(int a : try_vec){
        ans.push_back(try_mp[a]);
    }
    for(int a : ans){
        cout<<a;
    }
}
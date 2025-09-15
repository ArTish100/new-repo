#include<iostream>
using namespace std;
int main(){
    int Arr[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    int Arr1[5][3];
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout<<Arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            Arr1[j][i] = Arr[i][j];
        }
    }
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout<<Arr1[i][j]<<" ";
        }
        cout<<"\n";
    }
}
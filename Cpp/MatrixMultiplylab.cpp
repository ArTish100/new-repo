#include<iostream>
using namespace std;
int main(){
    int Arr1[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    int Arr2[5][2]={{1,2},{3,4},{5,6},{7,8},{9,10}};
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout<<Arr1[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            cout<<Arr2[i][j]<<" ";
        }
        cout<<"\n";
    }
    int Arr3[3][2];
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 2 ; j++)
        for(int k = 0 ; j < 5 ; k++){
            Arr3[i][j] = Arr3[i][j] + (Arr1[i][k]*Arr2[k][j]);
        }
    }
}
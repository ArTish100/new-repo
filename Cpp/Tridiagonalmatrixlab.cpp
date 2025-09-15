#include<iostream>
using namespace std;
int main(){
    int mat[4][4];
    int num;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(i-j>1 || j-i>1){
                mat[i][j] = 0;
            }else{
                cout<<"Enter number : ";
                cin>>num;
                mat[i][j] = num;
            }
        }
    }
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
#include<iostream>
using namespace std;






int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int **A = new int *[n];
    for(int i=0;i<n;i++){
        A[i] = new int [n];
        for(int j=0;j<n;j++){
            A[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j];
        }
    }
}
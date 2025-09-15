#include<iostream>
using namespace std;
int main(){
    int Arr1[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    int row[3][1];
    int col[1][5];
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout<<Arr1[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i = 0 ; i < 3 ; i++){
        int r = 0;
        for(int j = 0 ; j < 5 ; j++){
            r = r + Arr1[i][j];
        }
        row[i][0] = r;
    }
    for(int i = 0 ; i < 5 ; i++){
        int r = 0;
        for(int j = 0 ; j < 3 ; j++){
            r = r + Arr1[j][i];
        }
        col[0][i] = r;
    }
    for(int i = 0 ; i < 3 ; i++){
        cout<<row[i][0]<<"\n";
    }
    cout<<"\n";
    for(int i = 0 ; i < 5 ; i++){
        cout<<col[0][i]<<" ";
    }
}
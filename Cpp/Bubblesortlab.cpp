#include<iostream>
using namespace std;
int main(){
    int Arr[10]={9,1,7,2,8,3,5,6,4,0};
    for(int i = 1 ; i < 11 ; i++){
        int n = 0;
        for(int j = 0 ; j < 10 ; j++){
            if(Arr[j] > Arr[j+1]){
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                n = 1;
            }
        }
        if(n == 0){
            break;
        }
    }
    for(int i = 0 ; i < 10 ; i++){
        cout<<Arr[i]<<" ";
    }
}
#include<iostream>
using namespace std;

int main(){
    int Arr[10]={1,2,3,4,5,6,7,8,9,10};
    int temp;
    for(int i = 0 ; i < 5 ; i++){
        temp = Arr[i];
        Arr[i] = Arr[10-i-1];
        Arr[10-i-1] = temp;
    }
    for(int i = 0 ; i < 10 ; i++){
        cout<<Arr[i];
    }
}
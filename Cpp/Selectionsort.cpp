#include<iostream>
using namespace std;
int main(){
    int Arr[10]={9,1,7,2,8,3,5,6,4,0};
    for(int i = 0 ; i <= 8 ; i++){
        int min = i;
        for(int j = i+1 ; j <= 9 ; j++){
            if(Arr[min]>Arr[j]){
                min = j;
            }
        }
        if(min!=i){
            int temp=Arr[i];
            Arr[i]=Arr[min];
            Arr[min]=temp;
        }
    }
    for(int i = 0 ; i < 10 ; i++){
        cout<<Arr[i]<<" ";
    }
}
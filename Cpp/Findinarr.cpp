#include <iostream>
using namespace std;
int findarr(int *arr){
    //cout<<arr[0];
    int a;
    cout<<"Enter the number you want : ";
    cin>>a;
    int l = 0,h = 10,m = 5;
    while(true){
        if(arr[l] == a){
            return 1;
        }else if(arr[h] == a){
            return 1;
        }
    }
    return 0;
}
int main(){
    int Arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int result = findarr(Arr);
    return 0;
}
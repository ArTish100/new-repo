#include<iostream>
using namespace std;
int main(){
    int Arr[10]={1,2,3,4,5,6,7,8,9,10};
    int a;
    cout<<"Enter number to search : ";
    cin>>a;
    int l = 0;
    int h = 9;
    int m;
    while(true){
        m = (h + l)/2;
        if(Arr[m] == a){
            break;
        }else if(a > Arr[m]){
            l = m + 1;
        }else{
            h = m - 1;
        }
    }
    cout<<m<<" "<<Arr[m];
}
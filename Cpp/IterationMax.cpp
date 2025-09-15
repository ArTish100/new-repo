#include<iostream>
using namespace std;
int findmax(int A[],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        int max1 = findmax(A,lb,mid);
        int max2 = findmax(A,mid+1,ub);
        if (max1>max2){
            cout<<"max1 : "<<max1<<endl;
            return max1;
        }else{
            cout<<"max2 : "<<max2<<endl;
            return max2;
        }
    }
}

int main(){
    int A[]={1};
    int max = findmax(A,0,0);
    cout<<max;

}
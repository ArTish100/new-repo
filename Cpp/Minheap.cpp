#include<iostream>
using namespace std;
void heapify(int A[],int N,int i){
    int small=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<N && A[left]<A[small]){
        small=left;
    }
    if(right<N && A[right]<A[small]){
        small=right;
    }
    if(small!=i){
        swap(A[i],A[small]);
        heapify(A,N,small);
    }
}
void heapsort(int A[],int N){
    for(int i = (N/2)-1 ; i >= 0 ; i--){
        heapify(A,N,i);
    }
    for(int i = N-1 ; i>0 ; i--){
        swap(A[i],A[0]);
        heapify(A,i,0);
    }
}
void displayArr(int A[],int N){
    for(int i = 0 ; i < N ; i++){
        cout<<A[i]<<"->";
    }
    cout<<endl;
}
int main(){
    int A[] = {3,9,7,5,6,2};
    int N = sizeof(A)/sizeof(A[0]);
    displayArr(A,N);
    heapsort(A,N);
    displayArr(A,N);
}
#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* link;
};
class Array{
    int n;
    int *Arr;
    int front;
    int rear;
    public:
        void init(int size);
        void enqueue(int a);
        void dequeue();
        void display();
};
void Array :: init(int size){
    n=size;
    Arr=new int[n];
    front=-1;
    rear=-1;
    return;
}
void Array::enqueue(int a){
    if(front == (rear+1)%n){
        cout<<"Overflow"<<endl;
    }else{
        if(front==-1){
            front = 0;
        }
        rear = (rear+1)%n;
        Arr[rear]=a;
    }
}
void Array::dequeue(){
    if(front==rear && rear==-1){
        cout<<"Underflow";
    }else{
        cout<<Arr[front]<<endl;
        if(front==rear){
            front = rear = -1;
        }else{
            front = (front+1)%n;
        }
        
    }
}
void Array :: display(){
    for(int i = front ; i <= rear ; i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    Array A1;
    A1.init(n);
    for(int i = 1 ; i < 10 ; i++){
        A1.enqueue(i);
    }
    A1.display();
    A1.dequeue();
    A1.display();
}
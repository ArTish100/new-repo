#include<iostream>
using namespace std;
#define MAX 5
class STACK{
    int value[MAX];
    int top;
    public:
        void init();
        int IsEmpty();
        int IsFull();
        void push(int a);
        int pop();
};
void STACK :: init(){
    top=-1;
}
int STACK :: IsEmpty(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return 1;
    }
}
int STACK :: IsFull(){
    if(top==(MAX)-1){
        cout<<"Stack is full"<<endl;
        return 1;
    }
}
void STACK :: push(int a){
    if(top!=MAX-1){
        top +=1;
        value[top] = a;
    }else{
        cout<<"OVERFLOW"<<endl;
    }
}
int STACK :: pop(){
    if (top==-1){
        cout<<"UNDERFLOW"<<endl;
    }else{
        int de = value[top];
        top = top - 1;
        return de;
    }
    
}
int main(){
    STACK S1;
    S1.init();
    S1.IsEmpty();
    S1.push(420);
    S1.push(69);
    S1.push(8);
    S1.push(5);
    S1.push(4);
    S1.IsFull();
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;
    S1.IsEmpty();
}
#include<iostream>
using namespace std;
#define MAX 20
class STACK{
    char value[MAX];
    int top;
    public:
        void init();
        int IsEmpty();
        int IsFull();
        void push(int a);
        int pop();
        void display();
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
void STACK :: display(){
    int t=top;
    while(t!=-1){
        cout<<value[t];
        t-=1;
    }
}
int main(){
    STACK S1;
    S1.init();
    S1.IsEmpty();
    char Str[30];
    cin>>Str;
    int i=0;
    while(Str[i]!='\0'){
        S1.push(Str[i]);
        i+=1;
    }
    S1.IsFull();
    S1.display();

}
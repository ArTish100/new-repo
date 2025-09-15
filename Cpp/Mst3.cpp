#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* link;
};
class List{
    Node* head;
    int top;
    int max;
    public:
        void init(int m);
        void display();
        void push(int a);
        void pop();
        void peek();
        bool IsFull();
        bool IsEmpty();
        void sum();
        void fun();
};
void List :: push(int a){
    if(top==max-1){
        cout<<"Overflow"<<endl;
    }else{
        Node* temp = new Node;
        temp->data = a;
        
        if(top==-1){
            
            temp->link = nullptr;
        }else{
            temp->link = head;

        }
        head = temp;
        top+=1;
        return;
    }
}
void List :: pop(){
    if(top==-1){
        cout<<"Underflow"<<endl;
        return;
    }else{
        Node* temp = head;
        head = temp->link;
        cout<<temp->data<<endl;
        free(temp);
        return;
    }
}
void List :: init(int m){
    head=nullptr;
    top = -1;
    max=m;
    return;
}
bool List :: IsFull(){
    if(top==max-1){
        return true;
    }
}
bool List :: IsEmpty(){
    if(top==-1){
        return true;
    }
}
void List :: display(){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp = temp->link;
    }
    return;
}
void List :: sum(){
    Node* temp = head;
    List L2;
    List L3;
    while(temp->link!=0 && temp->link->link!=0){
        int sume = 0;
        int sumo=0;
        sume = temp->data + temp->link->link->data;
        sumo = temp->link->data + temp->link->link->link->data;
        cout<<sume<<" ppp ";
        cout<<sumo<<"  ";
        L2.push(sume);
        L3.push(sumo);
        temp=temp->link->link;
        cout<<"work"<<endl;
    }
    cout<<"blah"<<endl;
    L2.display();
    L3.display();
}
int main(){
    List L1,L2,L3;
    int n;
    cout<<"Enter n : ";
    cin>>n;
    L1.init(2*n);
    L2.init(5);
    L3.init(5);
    for(int i = 2*n ; i >= 1 ; i--){
        L1.push(i);
    }

    L1.display();
    //L2.odd(L1);
    L1.sum();
}
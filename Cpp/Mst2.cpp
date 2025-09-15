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
        void InsertNodeAtEnd(int a);
        void InsertNodeAtFront(int a);
        void display();
        void push(int a);
        void pop();
        void peek();
        bool IsFull();
        bool IsEmpty();
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
void List :: peek(){
    if(top==-1){
        cout<<"Stack is empty";
    }else{
        cout<<head->data<<endl;
    }
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
void List :: init(int m){
    head=nullptr;
    top = -1;
    max=m;
    return;
}
void List :: InsertNodeAtEnd(int a){
    Node* temp = new Node;
    temp->data = a;
    temp->link = nullptr;
    if  (head==nullptr){
        head=temp;
        
    }else{
        Node* itr = head;
        while(itr->link!=nullptr){
            itr = itr->link;
        }
        itr->link = temp;
    }
    return;
}
void List :: InsertNodeAtFront(int a){
    Node* temp = new Node;
    temp->data = a;
    temp->link = nullptr;
    if  (head==nullptr){
        head=temp;
    }else{
        Node* itr = head;
        while(itr->link!=nullptr){
            itr = itr->link;
        }
        itr->link = temp;
    }
    return;
}
void List :: display(){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp = temp->link;
    }
    return;
}
int main(){
    List L1;
    L1.init(6);
    L1.pop();
    L1.push(2);
    L1.push(3);
    L1.push(9);
    L1.push(7);
    L1.push(4);
    L1.push(7);
    L1.push(10);
    L1.push(10);
    L1.display();
    cout<<"Try1"<<endl;
    L1.pop();
    L1.pop();
    cout<<"After popping"<<endl;
    L1.display();
}
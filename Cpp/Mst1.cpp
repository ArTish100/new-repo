#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* link;
};
class List{
    Node* head;
    public:
        void init();
        void InsertNodeAtEnd(int a);
        void InsertNodeAtFront(int a);
        void display();
};
void List :: init(){
    head=nullptr;
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
}
void List :: display(){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp = temp->link;
    }
}
int main(){
    List L1;
    L1.init();
    L1.InsertNodeAtEnd(2);
    L1.display();
    L1.InsertNodeAtEnd(3);
    L1.InsertNodeAtEnd(9);
    L1.InsertNodeAtEnd(7);
    L1.InsertNodeAtEnd(4);
    L1.display();
}
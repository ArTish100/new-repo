#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* link;
};
class List{
    
    public:
        Node* head=nullptr;
        void insertatend(int a);
        void display();
        void Printrev(Node* L);
};
void List::insertatend(int a){
    Node* temp = new Node;
    temp->data = a;
    temp->link = nullptr;
    if(head==nullptr){
        head  = temp;
    }else{
        Node* temp1 = head;
        while(temp1->link!=nullptr){
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }
}
void List :: display(){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}
void List:: Printrev(Node* L){
    Node* temp = L;
    if(temp==nullptr){
        return;
    }else{
        Printrev(L->link);
        cout<<temp->data<<"->";
    }
    
}
int main(){
    List L1;
    for(int i = 1 ; i < 6 ; i++){
        L1.insertatend(i);
    }
    L1.display();
    L1.Printrev(L1.head);
}
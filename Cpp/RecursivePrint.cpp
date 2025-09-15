#include <iostream>
using namespace std;
struct Node{
    Node* link;
    int data;
};
Node* head;
void insertNode(int a){
    Node* temp = new Node();
    temp->data = a;
    temp->link = NULL;
    if(head == NULL){
        head = temp;
    }else{
        Node* itr = head;
        while(itr->link != NULL){
            itr = itr->link;
        }
        itr->link = temp; 
    }
}
void displayNode(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}
void Print(Node* temp){
    if(temp == NULL) return;
    cout<<temp->data<<" ";
    Print(temp->link);
}
void RevPrint(Node* temp){
    if(temp == NULL) return;
    RevPrint(temp->link);
    cout<<temp->data<<" ";
}
int main(){
    head = NULL;
    insertNode(2);
    insertNode(8);
    insertNode(4);
    insertNode(5);
    insertNode(7);
    Print(head);
    cout<<"\n";
    RevPrint(head);
}
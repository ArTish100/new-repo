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
        while(itr->link == NULL){
            itr = itr->link;
        }
        itr->link = temp;
    }
}
void Print(Node* temp){
    cout<<temp->data;
    Print(temp->link);
}
void reverseList(Node* current){
    
    if(current->link == NULL){
        head = current;
        return;
    }
    reverseList(current->link);
    Node* next;
    next = current->link;
    next->link = current;
    current->link = NULL;
}
int main(){
    head = NULL;
    insertNode(2);
    insertNode(9);
    insertNode(3);
    insertNode(0);
    Print(head);
    reverseList(head);
    Print(head);
}
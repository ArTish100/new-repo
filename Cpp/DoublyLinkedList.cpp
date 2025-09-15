#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
};
Node* head;
void insertNode(int a){
    Node* temp = new Node();
    temp->data = a;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        Node* itr = head;
        while(itr->next != NULL){
            itr = itr->next;
        }
        itr->next = temp;
        temp->prev = itr;
    }
}
void Print(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data;
        temp = temp->next;
    }

}
void rPrint(){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<<temp->data;
        temp = temp->prev;
    }

}
int main(){
    head = NULL;
    insertNode(2);
    insertNode(5);
    insertNode(3);
    insertNode(7);
    Print();
    rPrint();
}
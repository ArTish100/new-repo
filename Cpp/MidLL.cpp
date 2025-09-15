#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
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
Node* middleNode(Node* Head){
    Node* temp = Head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->link;
    }
    int middle = count/2;
    for(int i = 0 ; i < middle ; i++){
        Head = Head->link;
    }
    return Head;
}
void Print(Node* Head){
    while(Head != NULL){
        cout<<Head->data<<" ";
        Head = Head->link;
    }
}
int main(){
    head = NULL;
    insertNode(9);
    insertNode(2);
    Print(head);
    middleNode(head);
    Node* mid = middleNode(head);
    Print(mid);
}
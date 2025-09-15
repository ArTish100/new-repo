#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
Node* head;
void push(int i){
    Node* temp = new Node;
    temp->data = i;
    temp->link = NULL;
    
    if(head == NULL){
        head = temp;
    }else{
        Node* itr = head;
        while(itr->link!=NULL){
            itr = itr->link;
        }
        itr->link = temp;
    }
}
void reverse(){
    Node* temp = head;
    Node* next;
    Node* prev = NULL;
    while(temp != NULL){
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}
    

int main(){
    head = NULL;
    Node* head1,* head2;
    head1 = NULL;
    head2 = NULL;
    for(int i = 0 ; i < 1 ; i++){
        push(i);
    }
    head1 = head;
    for(int i = 0 ; i < 1 ; i++){
        cout<<head1->data<<endl;
        head1 = head1->link;
    }
    reverse();
    head2 = head;
    for(int i = 0 ; i < 4 ; i++){
        cout<<head2->data<<" ";
        head2 = head2->link;
    }
    
    
}
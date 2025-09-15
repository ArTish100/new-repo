#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
void push(Node** head, int i){
    Node* temp = new Node;
    temp->data = i;
    temp->link = NULL;
    Node* itr = *head;
    if(*head == NULL){
        *head = temp;
    }else{
        while(itr->link!=NULL){
            itr = itr->link;
        }
        itr->link = temp;
    }
}
void reverse(Node** head){
    Node* head3 = *head;
    Node* head0 = NULL;
    int size = 0;
    while(head3 != NULL){
        size++;
        head3 = head3->link;
    }
    //cout<<size<<endl;
    for(int i = 0 ; i < size-1 ; i++){
        Node* head1 = *head;
        Node* head2 = *head;
        head2 = head2->link;
        while(head2->link != NULL){
            head1 = head1->link;
            head2 = head2->link;
        }
        /*cout<<"head1 = "<<head1<<endl;
        cout<<"head2 = "<<head2<<endl;
        cout<<"head1link = "<<head1->link<<endl;
        cout<<"head2link = "<<head2->link<<endl;*/
        if(i == 0){
            head0 = head2;
        }
        head2->link = head1;
        head1->link = NULL;
        //cout<<"h1link : "<<head1->link<<endl;
        //cout<<"h2link : "<<head2->link<<endl;
        
    }
    *head = head0;
}
int main(){
    Node* head = NULL;
    Node* head1,* head2;
    head1 = NULL;
    head2 = NULL;
    for(int i = 0 ; i < 4 ; i++){
        push(&head, i);
    }
    head1 = head;
    for(int i = 0 ; i < 4 ; i++){
        cout<<head1->data<<endl;
        head1 = head1->link;
    }
    reverse(&head);
    head2 = head;
    for(int i = 0 ; i < 4 ; i++){
        cout<<head2->data<<" ";
        head2 = head2->link;
    }
    
    
}
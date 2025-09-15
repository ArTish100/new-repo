#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
};

class DLL{
    Node *head=NULL;
    public:
        void InsertAtEnd(int a);
        void InsertAtBe(int a);
        void InsertInBtw(int a, int n);
        void DeleteNode(int a);
        void SearchNode(int a);
        void DisplayList();
};

void DLL::InsertAtBe(int a){
    Node *temp=new Node;
    temp->data=a;
    temp->prev=NULL;
    if(head!=NULL){
        temp->next=head;
        head->prev=temp;
    }else{
        temp->next=NULL;
    }
    
    head=temp;
}

void DLL::InsertAtEnd(int a){
    Node *temp=new Node;
    temp->data=a;
    temp->next=NULL;
    if(head == NULL){
        temp->prev=NULL;
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

void DLL::InsertInBtw(int a, int n){
    Node *temp=new Node;
    temp->data=a;
    Node *itr=head;
    for(int i = 1 ; i < n ; i++){
        itr=itr->next;
    }
    temp->prev=itr->prev;
    temp->next=itr;
    itr->prev->next=temp;
    itr->prev=temp;
}

void DLL::SearchNode(int a){
    Node *temp=head;
    int i = 1;
    while(temp->data != a && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        cout<<"Element not found"<<endl;
        return;
    }
    cout<<"Position is : "<<i;
}

void DLL::DeleteNode(int a){
    Node *temp=head;
    while(temp->data != a && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Element not found"<<endl;
        return;
    }
}

void DLL::DisplayList(){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    DLL D1;
    D1.InsertAtBe(10);
    D1.InsertAtBe(20);
    D1.InsertAtEnd(100);
    D1.InsertAtBe(30);
    D1.InsertAtEnd(40);
    D1.InsertAtEnd(50);
    D1.InsertAtEnd(60);
    D1.InsertAtBe(90);
    D1.InsertAtEnd(70);
    D1.InsertInBtw(22,3);
    D1.DisplayList();
    D1.SearchNode(100);
}
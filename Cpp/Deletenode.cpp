#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* key;
};
Node* head;
void insertval(int a){
    Node* temp = new Node();
    temp->value = a;
    temp->key = NULL;
    if(head == NULL){
        head = temp;
    }else{
    Node* itr = head;
    while(itr->key != NULL){
        itr = itr->key;
    }
    itr->key = temp;
    }    
}
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->value<<endl;
        temp = temp->key;
    }
}
void deletenode(int a){
    Node* temp = head;
    int count = 0;
    while(temp->key != NULL){
        if(count == 0 && temp->value == a){
            head = temp->key;
            free(temp);
        }
        if(temp->key->value == a){
            Node* temp1 = temp->key;
            temp->key = temp1->key;
            free(temp1);
        }
        temp = temp->key;
        count++;
    }
}
int main(){
    head = NULL;
    insertval(4);
    insertval(9);
    insertval(7);
    insertval(3);
    insertval(5);
    display();
    deletenode(5);
    deletenode(9);
    deletenode(3);
    deletenode(4);
    display();
}
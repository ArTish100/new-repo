#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* link;
};
class List{
    int n;
    Node* head;
    int front;
    int rear;
    public:
        void init(int size);
        void enqueue(int a);
        void dequeue();
        void display();
};
void List :: init(int size){
    n=size;
    head=nullptr;
    front=-1;
    rear=-1;
    return;
}
void List::enqueue(int a){
    if(front == (rear+1)%n){
        cout<<"Overflow"<<endl;
    }else{
        if(front==-1){
            front = 0;
        }
        rear = rear+1;
        Node* temp = new Node;
        temp->data;
        temp->link = nullptr;
        if (head == nullptr){
            head = temp;
        }else{
            Node* temp1 = head;
            for(int i = 0 ; i < rear ; i++){
                temp1=temp1->link;
            }
            temp1->link=temp;
        }
        
    }
}
void List::dequeue(){
    if(front==rear && rear==-1){
        cout<<"Underflow";
    }else{
        Node* temp = head;
        cout<<temp->data<<endl;
        if(front==rear){
            front = rear = -1;
        }else{
            front = (front+1)%n;
        }
        
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
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    List A1;
    A1.init(n);
    for(int i = 1 ; i < 10 ; i++){
        A1.enqueue(i);
    }
    A1.display();
    A1.dequeue();
    A1.display();
}
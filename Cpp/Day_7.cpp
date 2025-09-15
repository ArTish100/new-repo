#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* temp=new ListNode;
        temp=head;
        if(temp->next!=NULL){
            head=temp->next;
            temp->next=head->next;
            head->next=temp;
        }else
            return head;
        ListNode* two=new ListNode;
        two=temp->next;
        while(temp->next!=NULL && two->next!=NULL){
            temp->next=two->next;
            two->next=two->next->next;
            temp->next->next=two;
            temp=two;
            two=two->next;
        }
        return head;
    }
};
int main(){
    ListNode* head=new ListNode(2);
    head=new ListNode(3,head);
    head=new ListNode(4,head);//two
    head=new ListNode(5,head);//temp
    head=new ListNode(6,head);
    head=new ListNode(7,head);
    // cout<<head->next->val;
    Solution S;
    head=S.swapPairs(head);
    while(head!=NULL){
        cout<<head->val;
        head=head->next;
    }
}
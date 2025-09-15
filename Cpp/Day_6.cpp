#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode();
        temp->next=head;
        ListNode* one=temp;
        ListNode* two=temp;
        while(n!=-1){
            one=one->next;
            n--;
        }
        while(one!=NULL){
            one=one->next;
            two=two->next;
        }
        ListNode* ndel=two->next;
        two->next=two->next->next;
        delete ndel;
        return temp->next;

    }
};

int main(){
    ListNode* head=new ListNode(3);
    head=new ListNode(4,head);
    head=new ListNode(5,head);
    cout<<endl;
    Solution S;
    head=S.removeNthFromEnd(head,2);
    while(head!=NULL){
        cout<<head->val;
        head=head->next;
    }
}
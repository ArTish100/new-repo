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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=new ListNode;
        temp=head->next;
        if(temp->val == head->val){
            while(temp && temp->val == head->val){
                temp = temp->next;
            }
            return deleteDuplicates(temp);
        }else{
            head->next = deleteDuplicates(temp);
            return head;
        }
        return head;
    }
};

int main(){
    ListNode* head=new ListNode(2);
    head=new ListNode(2,head);
    head=new ListNode(2,head);//two
    head=new ListNode(6,head);//temp
    head=new ListNode(4,head);
    head=new ListNode(5,head);
    // cout<<head->next->val;
    Solution S;
    head=S.deleteDuplicates(head);
    while(head!=NULL){
        cout<<head->val;
        head=head->next;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

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

    ListNode* createList(ListNode* head, vector<int> listvec){
        ListNode* temp=new ListNode;
        for(int a : listvec){
            if(head==NULL){
                head = new ListNode(a);
                
            }
            else{
                head = new ListNode(a,head);
                  
            }
        }
        return head;
    }

    ListNode* printList(ListNode* head){
        if(!head)
            cout<<"empty"<<endl;
        ListNode* temp=head;
        while(temp!=NULL){
            cout<<temp->val;
            temp = temp->next;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(n!=1){
            temp1=temp1->next;
            n--;
        }
        while(temp1->next!=NULL){
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        if(head == temp2){
            return head->next;
        }
        temp1 = head;
        while(temp1->next!=temp2){
            temp1 = temp1->next;
        }
        temp1->next = temp2->next;
        return head;
    }
};

int main(){
    ListNode* head1 = NULL;
    Solution S;
    vector<int> vecnum1 = {4};
    reverse(vecnum1.begin(), vecnum1.end());
    head1 = S.createList(head1,vecnum1);
    S.printList(head1);
    cout<<endl;
    head1 = S.removeNthFromEnd(head1,1);
    cout<<endl;
    S.printList(head1);
}
// 1 2 3 4 5 6 8 9
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
        ListNode* temp=head;
        while(temp!=NULL){
            cout<<temp->val;
            temp = temp->next;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp3=new ListNode;
        ListNode* head = temp3;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val > temp2->val){
                temp3->next = temp2;
                temp2 = temp2->next;
            }else{
                temp3->next = temp1;
                temp1 = temp1->next;
            }
            temp3 = temp3->next;
        }
        if(temp1!=NULL){
            temp3->next = temp1;
        }else{
            temp3->next = temp2;
        }
        return head->next;
        
    }
};

int main(){
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    Solution S;
    vector<int> vecnum1 = {};
    vector<int> vecnum2 = {};
    reverse(vecnum1.begin(), vecnum1.end());
    reverse(vecnum2.begin(), vecnum2.end());
    head1 = S.createList(head1,vecnum1);
    head2 = S.createList(head2,vecnum2);
    head1 = S.mergeTwoLists(head1,head2);
    S.printList(head1);

}
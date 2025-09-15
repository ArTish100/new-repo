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

    // ListNode* reorderList(ListNode* head) {

    //     ListNode* temp1 = head;
    //     ListNode* temp2 = head->next;
    //     while(temp2!=NULL && temp2->next!=NULL){
    //         temp1 = temp1->next;
    //         temp2 = temp2->next->next;
    //     }
    //     ListNode* temp3 = temp1->next;
    //     temp1->next = NULL;
    //     temp1 = temp3;
    //     temp3 = temp3->next;
    //     temp1->next = NULL;
    //     temp2 = temp3;
    //     while(temp3!=NULL){
    //         temp2 = temp3;
    //         temp3 = temp3->next;
    //         temp2->next = temp1;
    //         temp1 = temp2;
    //     }
    //     ListNode* temp4 = head;
    //     while(temp4!=NULL && temp1!=NULL){
    //         temp3 = temp4->next;
    //         temp2 = temp1->next;
    //         temp4->next = temp1;
    //         temp1->next = temp3;
    //         temp4 = temp3;
    //         temp1 = temp2;            
            
    //     }
    //     return head;

    // }
    ListNode* reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while (second != nullptr) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        ListNode* first = head;
        second = prev;
        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
        return head;
    }
};

int main(){
    ListNode* head1 = NULL;
    Solution S;
    vector<int> vecnum1 = {1,2};
    reverse(vecnum1.begin(), vecnum1.end());
    head1 = S.createList(head1,vecnum1);
    S.printList(head1);
    cout<<endl;
    head1 = S.reorderList(head1);
    S.printList(head1);
}
#include <iostream>
using namespace std;
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1, *ptr2;
        ptr1 = l1;
        ptr2 = l2;
        int* arr = new int; 
        int x;
        int c=0;
        int i=0;
        while(ptr1!=nullptr && ptr2!=nullptr){
            x = c + ptr1->val + ptr2->val;
            c = x/10;
            x = x%10;
            arr[i] = x;
            i++;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ListNode* ptr;
        if(ptr1==nullptr){
            ptr = ptr2;
        }else{
            ptr = ptr1;
        }
        while(ptr!=nullptr){
            x = c + ptr->val;
            c = x/10;
            x = x%10;
            arr[i] = x;
            i++;
            ptr = ptr->next;
        }
        if(c!=0){
            arr[i] = c;
            i++;
        }
        i = i-1;
        ListNode *tail = new ListNode(arr[i]);
        i = i-1;
        while(i>=0){
            tail = new ListNode(arr[i],tail);
            i--;
        }
        return tail;
    }

    ListNode* convertList(int* a,int s){
        cout<<a[4]<<endl;
        int i = 0;
        int x = a[i];
        ListNode* head = new ListNode(x);
        i=i+1;
        while(i!=s){
            x = a[i];
            head = new ListNode(x,head);
            i=i+1;
        }
        return head;
    }
};



int main(){
    Solution a;
    int l1[5] = {2,3,4,5,6};
    int s1 = sizeof(l1)/sizeof(l1[0]);
    int l2[4] = {1,1,1,1};
    int s2 = sizeof(l2)/sizeof(l2[0]);

    ListNode* head1 = a.convertList(l1,s1);
    ListNode* head2 = a.convertList(l2,s2);

    ListNode* head = a.addTwoNumbers(head1,head2);
    while(head!=nullptr){
        cout<<head->val<<",";
        head=head->next;
    }

}
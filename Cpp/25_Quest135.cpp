//25. Reverse Nodes in k-Group

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
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
    ListNode* createLL(vector<int>& vec){
        ListNode* temp = nullptr;
        reverse(vec.begin(),vec.end());
        for(int a : vec){
            temp = new ListNode(a, temp);
        }
        return temp;
    }

    void printLL(ListNode* head){
        while(head!=nullptr){
            cout<<head->val<<' ';
            head = head->next;
        }
        cout<<endl;
        return;
    }

    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* nxt_node;
        ListNode* prv_node = NULL;
        while(temp!=NULL){
            nxt_node = temp->next;
            temp->next = prv_node;
            prv_node = temp;
            temp = nxt_node;
        }
        return prv_node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* ptr1 = head;
        ListNode* ptr2;
        ListNode* prev;
        while(temp!=NULL){
            for(int i=0;i<k;i++){
                if(temp!=NULL){
                    ptr2 = temp;
                    temp = temp->next;
                }else{
                    if(prev!=NULL)
                        prev->next = ptr1;
                    return head;
                }
            }
            ptr2->next = NULL;
            if(head==ptr1)
                head = reverseLL(ptr1);
            else{
                prev->next = reverseLL(ptr1);
            }
            ptr1->next = temp;
            prev = ptr1;
            prev->next = NULL;
            ptr1 = temp;
            ptr2 = ptr1;
        }
        return head;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.reverseKGroup(head,2);
    S.printLL(head);
}
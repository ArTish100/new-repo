//2095. Delete the Middle Node of a Linked List

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

    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            head->next = NULL;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while(fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if(fast==NULL)
                break;
        }
        prev->next = slow->next;
        return head;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3,4};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.deleteMiddle(head);
    S.printLL(head);
    
}
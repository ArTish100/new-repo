//234. Palindrome Linked List

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

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* temp = head;
        while(temp!=NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        else if(head->next->next==NULL && head->val!=head->next->val)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2;
        head2 = reverseLL(slow);
        printLL(head2);
        while(head!=slow){
            if(head->val!=head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
            

    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,1,1};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    cout<<S.isPalindrome(head);
    
}




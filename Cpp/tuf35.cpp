//206. Reverse Linked List


#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

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

    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* next;
        while(temp!=nullptr){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.reverseList(head);
    S.printLL(head);
}
//876. Middle of the Linked List

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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

    ListNode* middleNode(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp2!=nullptr && temp2->next!=nullptr){
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }
        return temp1;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3,4,5,6};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.middleNode(head);
    cout<<head->val;
}
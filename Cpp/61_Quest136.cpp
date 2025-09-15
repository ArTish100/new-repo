//61. Rotate List

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        else if(k == 0)
            return head;ListNode* temp;
        ListNode* end;
        for(int i=0;i<k;i++){
            temp = head;
            while(temp->next->next!=NULL)
                temp = temp->next;
            end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }
        return head;
    }

    ListNode* rotateRight1(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        else if(k == 0)
            return head;
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next!=NULL){
            temp = temp->next;
            cnt++;
        }
        k = k%cnt;
        temp = reverseLL(head);
        head->next = temp;
        while(k!=0){
            head = head->next;
            temp = temp->next;
            k--;
        }
        head->next = NULL;
        head = reverseLL(temp);
        return head;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.rotateRight(head,1);
    S.printLL(head);
}
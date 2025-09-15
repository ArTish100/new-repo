//19. Remove Nth Node From End of List

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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* back = head;
        while(n){
            front = front->next;
            n--;
        }
        if(front == NULL){
            head = head->next;
            return head;
        }
        ListNode* prev;
        while(front!=NULL){
            front = front->next;
            prev = back;
            back = back->next;
        }
        prev->next = back->next;
        return head;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3,4,5};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.removeNthFromEnd(head,1);
    S.printLL(head);
    
}




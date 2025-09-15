//328. Odd Even Linked List

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

    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        while(odd->next!=NULL || even->next!=NULL){
            odd->next = even->next;
            if(odd->next==NULL){
                break;
            }
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
            if(even==NULL)
                break;
        }
        odd->next = evenhead;
        return head;
        
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3,4,5,6};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.oddEvenList(head);
    S.printLL(head);
    
}




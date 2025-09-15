//142. Linked List Cycle II


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

    ListNode *detectCycle1(ListNode *head) {
        unordered_map<ListNode*, int> LL_map;
        while(head!=NULL){
            if(LL_map.find(head) != LL_map.end()){
                return head;
            }
            LL_map[head]=1;
        }
        return head;
    }


    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return slow;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.detectCycle(head);
    S.printLL(head);
}




//Remove duplicates from sorted DLL

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:

    ListNode* insertDLL(ListNode* head, vector<int> vec){
        ListNode* temp;
        for(int a : vec){
            if(head == NULL){
                head = new ListNode(a);
                temp = head;
            }else{
                temp->next = new ListNode(a,NULL,temp);
                temp = temp->next;
            }
        }
        return head;
    }

    void printDLL(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<" "; 
            head = head->next;
        }
        cout<<endl;
        return;
    }

    void printVecPair(vector<pair<int, int>> vec){
        for(auto a : vec){
            cout<<a.first<<" "<<a.second<<endl;
        }
        return;
    }

    ListNode *removeDuplicates(ListNode *head) {
        ListNode* temp = head;
        ListNode* nxt_node;
        temp = temp->next;
        while(temp!=NULL){
            if(temp->val == temp->prev->val){
                nxt_node = temp->next;
                temp->prev->next = nxt_node;
                if(nxt_node!=NULL){
                    nxt_node->prev = temp->prev;
                }
                delete temp;
                    temp = nxt_node;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};

int main(){
    Solution S;
    vector<int> vec = {1,1,1,2,3,3,3,4,4};
    int target = 2;
    ListNode* head = NULL;
    head = S.insertDLL(head,vec);
    S.printDLL(head);
    vector<pair<int, int>> ans;
    head = S.removeDuplicates(head);
    S.printDLL(head);
}
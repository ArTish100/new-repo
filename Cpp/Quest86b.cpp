#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* random;
    
    ListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
    
    ListNode(int _val, ListNode *next) {
        val = _val;
        this->next = next;
        random = NULL;
    }
};

class Solution {
public:

    ListNode* createList(ListNode* head, vector<int> listvec){
        //ListNode* temp=new ListNode;
        for(int a : listvec){
            if(head==NULL){
                head = new ListNode(a);
            }
            else{
                head = new ListNode(a,head);
            }
        }
        return head;
    }

    ListNode* printList(ListNode* head){
        if(!head)
            cout<<"empty"<<endl;
        ListNode* temp=head;
        while(temp!=NULL){
            cout<<temp->val;
            temp = temp->next;
        }
    }

    ListNode* copyRandomList(ListNode* head) {
        unordered_map<ListNode*, ListNode*> n_map;
        n_map[NULL] = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            if(n_map.find(temp)==n_map.end()){
                n_map[temp] = new ListNode(0);
            }
            n_map[temp]->val = temp->val;
            if(n_map.find(temp->next)==n_map.end()){
                n_map[temp->next] = new ListNode(0);
            }
            n_map[temp]->next = n_map[temp->next];
            if(n_map.find(temp->random)==n_map.end()){
                n_map[temp->random] = new ListNode(0);
            }
            n_map[temp]->random = n_map[temp->random];
            temp = temp->next;
        }
        return n_map[head];
    }
};

int main(){
    ListNode* head1 = NULL;
    Solution S;
    vector<int> vecnum1 = {4,5};
    reverse(vecnum1.begin(), vecnum1.end());
    head1 = S.createList(head1,vecnum1);
    S.printList(head1);
    cout<<endl;
    head1 = S.copyRandomList(head1);
    cout<<"out"<<endl;
    S.printList(head1);
}
// 1 2 3 4 5 6 8 9
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    ListNode* createList(ListNode* head, vector<int> listvec){
        ListNode* temp=new ListNode;
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
        ListNode* temp=head;
        while(temp!=NULL){
            cout<<temp->val;
            temp = temp->next;
        }
    }

    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> umap_list;
        while(head!=NULL){
            if(umap_list[head]!=1)
                umap_list[head]=1;
            else
                return false;
            head=head->next;
        }
        return true;
    }
};

int main(){
    ListNode* head1 = NULL;
    Solution S;
    vector<int> vecnum1 = {1,1,2,3,4};
    reverse(vecnum1.begin(), vecnum1.end());
    head1 = S.createList(head1,vecnum1);
    head1->next->next->next = head1->next;
    cout<<S.hasCycle(head1);
    //S.printList(head1);

}
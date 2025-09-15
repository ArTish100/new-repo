//Sort a LL of 0's 1's and 2's by changing links

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

    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        ListNode* temp1 = head;
        ListNode* prev = NULL;
        while(temp1!=NULL){
            if(temp1->val == 0 && prev!=NULL){
                if(temp1->next==NULL){
                    temp = prev;
                }
                cout<<"work";
                prev->next = temp1->next;
                temp1->next = head;
                head = temp1;
                temp1 = prev->next;
                printLL(head);
                continue;
            }else if(temp1->val == 2 && prev!=NULL){
                if(temp==temp1){
                    break;
                }
                prev->next = temp1->next;
                temp1->next = NULL;
                temp->next = temp1;
                temp = temp1;
                temp1 = prev->next;
                continue;
            }
            prev = temp1;
            temp1 = temp1->next;
        }
        return head;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,0,2,0,1};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.sortList(head);
    S.printLL(head);
}
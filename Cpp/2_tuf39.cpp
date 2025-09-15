//2. Add Two Numbers

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

    ListNode *reverseLL(ListNode *head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* forw;
        while(temp!=NULL){
            forw = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forw;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1;
        int num2;
        ListNode* ans = NULL;
        ListNode* prev;
        ListNode* temp;
        int sum = 0;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL){
                num1 = l1->val;
                l1 = l1->next;
            }   
            else
                num1 = 0;
            if(l2!=NULL){
                num2 = l2->val;
                l2 = l2->next;
            }
            else
                num2 = 0;
            sum += num1+num2;
            temp = new ListNode(sum%10);
            sum = sum/10;
            if(ans==NULL){
                ans = temp;
                prev = temp;
            }
            else{
                prev->next = temp;
                prev = temp;
            }
        }
        if(sum>=1){
            temp = new ListNode(sum%10);
            prev->next = temp;
        }
        return ans;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {9,0,2,3};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    vector<int> vec1 = {9};
    ListNode* l1;
    l1 = S.createLL(vec1);
    S.printLL(l1);
    head = S.addTwoNumbers(head,l1);
    S.printLL(head);
}
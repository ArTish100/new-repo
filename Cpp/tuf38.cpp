//Add one to a number represented by LL

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

    ListNode *addOne(ListNode *head) {
        ListNode* temp = head;
        int num = 0;
        while(temp->next!=NULL){
            num = 10*num+(temp->val);
            temp = temp->next;
        }
        num = 10*num+(temp->val);
        if(num%10 == 9){
            num = num+1;
            temp = head;
            while(temp->next!=NULL){
                temp->val = num%10;
                num = num/10;
                temp = temp->next;
            }
            temp->val = num%10;
            num = num/10;
            if(num>=1){
                temp->next = new ListNode(num);
            }
            head = reverseLL(head);
        }
        else{
            temp->val = (temp->val)+1;
        }
        return head;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {9,0};
    ListNode* head;
    head = S.createLL(vec);
    S.printLL(head);
    head = S.addOne(head);
    S.printLL(head);
}
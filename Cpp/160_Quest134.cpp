//160. Intersection of Two Linked Lists

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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map <ListNode*, int> LL_map;
        while(headA!=NULL || headB!=NULL){
            if(headA!=NULL){
                if(LL_map.find(headA)!=LL_map.end()){
                    return headA;
                }
                LL_map[headA] = 1;
                headA = headA->next;
            }
            if(headB!=NULL){
                if(LL_map.find(headB)!=LL_map.end()){
                    return headB;
                }
                LL_map[headB] = 1;
                headB = headB->next;
            }
        }
        return NULL;
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {1,2,3,4};
    vector<int> vec1 = {1,2,3,4};
    ListNode* head;
    ListNode* head1;
    head = S.createLL(vec);
    head1 = S.createLL(vec1);
    S.printLL(head);
    S.printLL(head1);
    head = S.getIntersectionNode(head,head1);
}
//Find pairs with given sum in DLL

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

    vector<pair<int, int>> findPairsWithGivenSum(ListNode *head, int target) {
        unordered_map<int,int> LL_map;
        vector<pair<int, int>> ans;
        pair<int,int> pans;
        ListNode* temp = head;
        while(temp!=NULL){
            if(LL_map.find(target-temp->val)==LL_map.end()){
                LL_map[temp->val] = 1;
            }else{
                pans.first = temp->val;
                pans.second = target-temp->val;
                ans.push_back(pans);
                LL_map.erase(temp->val);
            }
            temp = temp->next;
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {2,3,-1,4,2};
    int target = 2;
    ListNode* head = NULL;
    head = S.insertDLL(head,vec);
    S.printDLL(head);
    vector<pair<int, int>> ans;
    ans = S.findPairsWithGivenSum(head,target);
    S.printVecPair(ans);
}
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:


    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> myqueue;
        vector<int> ans;
        TreeNode* temp;
        myqueue.push(root);
        while(!myqueue.empty()){
            temp = myqueue.front();
            myqueue.pop();
            
            if(temp==NULL){
                ans.push_back(0);
                
            }
            else 
                ans.push_back(temp->val);
            if(temp!=NULL){
                myqueue.push(temp->left);
                myqueue.push(temp->right);
            }
                
        }
        int s = ans.size();
        for(int i = 0 ; i < s ; i++){
            cout<<ans[i];
        }
        vector<vector<int>> finalans;
        for(int i = 0 ; i < s ; i++){
            int p = pow(2,i);
            for(int j = 2*i ; j < p;j++){
                if(ans[j]!=0)
                    finalans[i][j] = ans[j];
            }
        }
        return finalans;
    }
};

int main(){
    Solution S;
    TreeNode* head = new TreeNode(3);
    TreeNode* temp = new TreeNode(15);
    TreeNode* temp1 = new TreeNode(7);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20, temp, temp1);
    S.levelOrder(head);
    

    // [3,9,20,null,null,15,7]
}
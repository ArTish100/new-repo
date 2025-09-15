//Inorder Successor/Predecessor in BST

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

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
    void recurConstTree(vector<int> &ans, int i, TreeNode* root){
        if(i>=ans.size())
            return;
        TreeNode* temp = new TreeNode(ans[i]);
        TreeNode* itr = root;
        while(itr){
            if(itr->val < temp->val){
                if(!itr->right){
                    itr->right = temp;
                    break;
                }
                itr=itr->right;
            }else{
                if(!itr->left){
                    itr->left = temp;
                    break;
                }
                itr=itr->left;
            }
        }
        recurConstTree(ans, i+1, root);
        return;
    }

    TreeNode* constructBST(vector<int> ans){
        TreeNode* root = new TreeNode(ans[0]);
        recurConstTree(ans, 1, root);
        return root;
    }

    void intprintAns(vector<int> ans){
        for(auto b : ans){
            // for(int a : b){
            //     cout<<a<<" "<<endl;
            // }
            // cout<<endl;
            cout<<b<<endl;
        }
    }
    void inorderTraversal(TreeNode* root, int key, vector<TreeNode*> &ans){
        if(!root)
            return;
        inorderTraversal(root->left, key, ans);
        if(root->val < key)
            ans[0] = root;
        if(root->val > key){
            if(!ans[1])
                ans[1] = root;
            return;
        }
        inorderTraversal(root->right, key, ans);
        return;
    }
    vector<TreeNode*> findPreSuc(TreeNode* root, int key) {
        vector<TreeNode*> ans = {NULL,NULL};
        inorderTraversal(root, key, ans);
        return ans;
    }
};

int main(){
    Solution S;
    // int N = NULL;
    vector<int> vec = {11, 6, 12, 5, 9, 13, 3, 10};
    TreeNode* root = S.constructBST(vec);
    vector<TreeNode*> ceil;
    ceil=S.findPreSuc(root, 13);
    if(ceil[0])
        cout<<ceil[0]->val<<endl;
    if(ceil[1])
        cout<<ceil[1]->val;
}
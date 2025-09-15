//Boundary Traversal of Binary Tree

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
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
    TreeNode* recurConstTree(vector<int> &ans, int i){
        if(i>=ans.size() || ans[i] == NULL)
            return NULL;
        TreeNode* root = new TreeNode(ans[i]);
        root->left = recurConstTree(ans, 2*i+1);
        root->right = recurConstTree(ans, 2*i+2);
        return root;
    }

    TreeNode* constructTree(vector<int> ans){
        TreeNode* root = recurConstTree(ans, 0);
        return root;
    }

    void intprintAns(vector<int> ans){
        for(auto b : ans){
            // for(int a:b){
            //     cout<<a<<" "<<endl;
            // }
            // cout<<endl;
            cout<<b<<endl;
        }
    }
    void leavesRecurFunc(TreeNode* root, vector<int> &ans){
        if(!root->left && !root->right)
            ans.push_back(root->val);
        if(root->left)
            leavesRecurFunc(root->left, ans);
        if(root->right)
            leavesRecurFunc(root->right, ans);
    }
    void rightRecurFunc(TreeNode* root, vector<int> &ans){
        root = root->right;
        vector<int> rev;
        while(root){
            cout<<root->val<<endl;
            if(root->left || root->right)
                rev.push_back(root->val);
            if(root->right!=NULL){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        reverse(rev.begin(),rev.end());
        for(int a : rev){
            ans.push_back(a);
        }
    }
    void leftRecurFunc(TreeNode* root, vector<int> &ans){
        root = root->left;
        while(root){
            if(root->left || root->right)
                ans.push_back(root->val);
            if(root->left!=NULL){
                root = root->left;
            }else{
                root = root->right;
            }
        }
    }

    vector<int> boundaryTraversal(TreeNode *root) {
        if(root == NULL)
            return {};
        vector<int> ans;
        if(root->left || root->right)
            ans.push_back(root->val);
        leftRecurFunc(root, ans);
        leavesRecurFunc(root, ans);
        rightRecurFunc(root, ans);
        return ans;
    }
};

int main(){
    Solution S;
    int N = NULL;
    vector<int> vec = {1, N, 2, N, N, N, 3, N, N, N, N, N, N, N, 4};
    TreeNode* root = S.constructTree(vec);
    vector<int> ans;
    ans = S.boundaryTraversal(root);
    S.intprintAns(ans);
}
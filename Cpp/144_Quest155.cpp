//144. Binary Tree Preorder Traversal

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
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
        for(int a:ans){
            cout<<a<<" ";
        }
    }
    void dfs(vector<int> &ans, TreeNode* root){
        ans.push_back(root->val);
        if(root->left!=NULL)
            dfs(ans, root->left);
        if(root->right!=NULL)
            dfs(ans, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> ans = {1,NULL,2,NULL,NULL,3};
    TreeNode* root = NULL;
    root = S.constructTree(ans);
    ans = S.preorderTraversal(root);
    S.intprintAns(ans);
}
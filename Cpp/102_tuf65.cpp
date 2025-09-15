//102. Binary Tree Level Order Traversal

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

    void intprintAns(vector<vector<int>> ans){
        for(auto b : ans){
            for(int a:b){
                cout<<a<<" "<<endl;
            }
            cout<<endl;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> qtree;
        qtree.push(root);
        vector<int> dstr;
        vector<vector<int>> ans;
        int s;
        while(!qtree.empty()){
            s = qtree.size();
            for(int i=0;i<s;i++){
                TreeNode* temp = qtree.front();
                dstr.push_back(temp->val);
                qtree.pop();
                if(temp->left!=NULL)
                    qtree.push(temp->left);
                if(temp->right!=NULL)
                    qtree.push(temp->right);
            }
            ans.push_back(dstr);
            dstr.clear();
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = NULL;
    root = S.constructTree(vec);
    vector<vector<int>> ans;
    ans = S.levelOrder(root);
    S.intprintAns(ans);
}
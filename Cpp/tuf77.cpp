//Check for Children Sum Property in a Binary Tree

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
    TreeNode* recurConstTree(vector<int> &ans, int i){
        if(i>=ans.size() || ans[i] == -1)
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

    void printVec(vector<vector<int>> ans){
        for(auto b : ans){
            for(int a : b){
                cout<<a<<" "<<endl;
            }
            cout<<endl;
        }
    }
    void printTree(TreeNode* root){
        queue<TreeNode*> qtree;
        qtree.push(root);
        TreeNode* temp;
        int qsize;
        int count;
        while(!qtree.empty()){
            qsize = qtree.size();
            count=0;
            for(int i=0;i<qsize;i++){
                temp = qtree.front();
                qtree.pop();
                if(temp){
                    cout<<temp->val<<" ";
                    qtree.push(temp->left);
                    qtree.push(temp->right);
                }
                    
                else{
                    cout<<0<<" ";
                    qtree.push(temp);
                    qtree.push(temp);
                    count++;
                }
            }
            cout<<endl;
            if(count==qsize)
                break;
        }
    }
    int isSumProperty(TreeNode *root) {
        if(!root || (!root->left && !root->right))
            return true;
        int sum =0;
        if(root->left)
            sum = root->left->val;
        if(root->right)
            sum = root->right->val;
        return (sum==root->val) && isSumProperty(root->left) && isSumProperty(root->right);
    }
    void applyChildrenSumProperty(TreeNode* root){
        if(!root)
            return;
        int sum = 0;
        if(root->left)
            sum += root->left->val;
        if(root->right)
            sum += root->right->val;
        if(root->val <= sum){
            root->val = sum;
        }else{
            if(root->left)
                root->left->val = root->val;
            if(root->right)
                root->right->val = root->val;
        }

        applyChildrenSumProperty(root->left);
        applyChildrenSumProperty(root->right);

        sum = 0;
        if(root->left)
            sum += root->left->val;
        if(root->right)
            sum += root->right->val;
        if(root->left || root->right){
            root->val = sum;
        }
    }
};

int main(){
    Solution S;
    int N = -1;
    vector<int> vec = {3, 3, N, 2, 1, N, N, 2, N, N, N};
    TreeNode* root = S.constructTree(vec);
    S.printTree(root);
    // cout<<S.isSumProperty(root);
}
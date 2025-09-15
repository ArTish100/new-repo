//110. Balanced Binary Tree

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

    int calcHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        int x, y;
        x = 1+calcHeight(root->left);
        y = 1+calcHeight(root->right);
        return max(x,y);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return 1;
        int x, y;
        x = calcHeight(root->left);
        y = calcHeight(root->right);
        return abs(x-y)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(){
    Solution S;
    vector<int> vec = {3,9,20,NULL,NULL,2,4};
    TreeNode* root = S.constructTree(vec);
    int ans;
    ans = S.isBalanced(root);
    cout<<ans;
}
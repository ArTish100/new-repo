//101. Symmetric Tree

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
            // for(int a : b){
            //     cout<<a<<" "<<endl;
            // }
            // cout<<endl;
            cout<<b<<endl;
        }
    }

    bool checkSymmetry(TreeNode* root1, TreeNode* root2){
        if(!root1 || !root2)
            return root1==root2;
        return root1->val == root2->val && checkSymmetry(root1->left, root2->right) && checkSymmetry(root2->left, root1->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return checkSymmetry(root->left, root->right);
    }
};

int main(){
    Solution S;
    int N = NULL;
    vector<int> vec = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = S.constructTree(vec);
    vector<int> ans;
    cout<<S.isSymmetric(root);
}
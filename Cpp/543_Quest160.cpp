//543. Diameter of Binary Tree

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
    int countMaxLength(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        int x,y;
        x = countMaxLength(root->left, ans);
        y = countMaxLength(root->right, ans);
        ans = x+y;
        return max(1+x, 1+y);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        countMaxLength(root, ans);
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {3,9,20,NULL,NULL,2,4};
    TreeNode* root = S.constructTree(vec);
    int ans;
    ans = S.diameterOfBinaryTree(root);
    cout<<ans;
}
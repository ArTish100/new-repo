//653. Two Sum IV - Input is a BST

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_set>

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
unordered_set<int> uset;
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

    bool findDiff(TreeNode* root, int k){
        if(!root)
            return false;
        if(k==root->val){
            return true;
        }
        return findDiff(root->left, k) || findDiff(root->right, k);
    }

    bool findTarget1(TreeNode* root, int k, TreeNode* temp) {
        if(!temp)
            return false;
        if(temp->val!=k-temp->val && findDiff(root, k-temp->val))
            return true;
        return findTarget1(root, k, temp->left) || findTarget1(root->right, k, temp->right);
    }

    // bool findTarget(TreeNode* root, int k) {
    //     return findTarget1(root, k, root);
    // }

    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        if(uset.count(k-root->val))
            return true;
        uset.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
    
};

int main(){
    Solution S;
    vector<int> vec = {5,3,6,2,4,7};
    TreeNode* root = S.constructBST(vec);
    cout<<S.findTarget(root, 11);
}
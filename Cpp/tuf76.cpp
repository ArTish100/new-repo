//Print Root to Node Path in a Binary Tree
//Merge 2 BST's

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

    void printVecInVec(vector<vector<int>> ans){
        for(auto a : ans){
            for(auto b : a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
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
    void inorderTraversal(TreeNode* root, vector<int> &ans){
        if(!root)
            return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
        return;
    }
    bool getPath(vector<int> &ans, TreeNode* root, int val){
        // cout<<val<<endl;
        if(root==NULL)
            return false;
        ans.push_back(root->val);
        if(root->val == val)
            return true;
        if(getPath(ans, root->left, val) || getPath(ans, root->right, val)){
            return true;
        }
        ans.pop_back();
        return false;
        
    }
    bool getPath1(vector<vector<int>> &dstr, vector<int> &ans, TreeNode* root){
        // cout<<val<<endl;
        if(root==NULL)
            return false;
        ans.push_back(root->val);
        if(!root->left && !root->right){
            dstr.push_back(ans);
            return false;
        } 
        if(getPath1(dstr, ans, root->left) || getPath1(dstr, ans, root->right)){
            return true;
        }
        ans.pop_back();
        return false;
        
    }
    vector<int> rootToNode(TreeNode* root, int val){
        vector<int> ans;
        getPath(ans, root, val);
        return ans;
        
    }
    vector<vector<int>> Paths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> dstr;
        getPath1(ans, dstr, root);
        return ans;
    }
};

int main(){
    Solution S;
    // int N = NULL;
    vector<int> vec = {5, 3, 6, 2, 4};
    TreeNode* root = S.constructBST(vec);
    vector<vector<int>> ceil;
    int val = 4;
    ceil=S.Paths(root);
    S.printVecInVec(ceil);
}
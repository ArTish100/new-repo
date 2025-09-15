//235. Lowest Common Ancestor of a Binary Search Tree

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
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while(temp){
            if(temp->val == p->val || temp->val == q->val){
                return temp;
            }
            if(temp->val > p->val && temp->val > q->val){
                temp = temp->left;
            }
            else if(temp->val < p->val && temp->val < q->val){
                temp = temp->right;
            }
            else
                return temp;
        }
        return temp;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        int val = root->val;
        if(val > p->val && val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(val < p->val && val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

int main(){
    Solution S;
    // int N = NULL;
    vector<int> vec = {5, 4, 6, 3, 7, 1};
    TreeNode* root = S.constructBST(vec);
    TreeNode* ceil;
    ceil=S.lowestCommonAncestor(root,root,root);
    cout<<"Val : "<<ceil;
}
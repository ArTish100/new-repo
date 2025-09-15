//173. Binary Search Tree Iterator

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
    
};

class BSTIterator {
public:
    vector<int> v;
    int vlen;
    int itr = 0;
    void inorderTraversal(TreeNode* root, vector<int> &ans){
        if(!root)
            return;
        inorderTraversal(root->left,ans);
        ans.push_back(root->val);
        inorderTraversal(root->right,ans);
        return;
    }
    BSTIterator(TreeNode* root) {
        inorderTraversal(root, this->v);
        this->vlen  = v.size();
    }
    
    int next() {
        this->itr+=1;
        return this->v[(this->itr)-1];
    }
    
    bool hasNext() {
        if(this->vlen<=this->itr)
            return false;
        return true;
    }
};

int main(){
    Solution S;
    vector<int> vec = {7,3,15,9,20};
    TreeNode* root = S.constructBST(vec);
    BSTIterator* bSTIterator = new BSTIterator(root);
    cout<<bSTIterator->next()<<endl;
    cout<<bSTIterator->next()<<endl;
    cout<<bSTIterator->hasNext()<<endl;
    cout<<bSTIterator->next()<<endl;
    cout<<bSTIterator->hasNext()<<endl;
    cout<<bSTIterator->next()<<endl;
    cout<<bSTIterator->hasNext()<<endl;
    cout<<bSTIterator->next()<<endl;
    cout<<bSTIterator->hasNext()<<endl;
}
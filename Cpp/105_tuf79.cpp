//105. Construct Binary Tree from Preorder and Inorder Traversal

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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

    void printVecOfVec(vector<vector<int>> ans){
        for(auto b : ans){
            for(auto a : b){
                cout<<a<<" "<<endl;
            }
            cout<<endl;
        }
    }

    void printVecOfInt(vector<int> ans){
        for(auto b : ans){
            cout<<b<<" "<<endl;
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
                    cout<<-1<<" ";
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


    unordered_map<int,int> umap;

    TreeNode* recurFunc(vector<int>& preorder, vector<int>& inorder, int &ind, int lptr, int rptr){
        if(lptr>rptr)
            return NULL;
        int curr = preorder[ind++];
        TreeNode* temp = new TreeNode(curr);
        cout<<temp->val<<endl;
        if(lptr==rptr)
            return temp;
        temp->left = recurFunc(preorder, inorder, ind, lptr, umap[curr]-1);
        temp->right = recurFunc(preorder, inorder, ind, umap[curr]+1, rptr);
        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int psize = inorder.size();
        for(int i=0;i<psize;i++){
            umap[inorder[i]] = i;
        }
        int p=0;
        return recurFunc(preorder, inorder, p, 0, psize-1);
    }
};

int main(){
    Solution S;
    int N = -1;
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    TreeNode* ans = S.buildTree(pre, in);
    S.printTree(ans);
}
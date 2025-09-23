//106. Construct Binary Tree from Inorder and Postorder Traversal

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


    TreeNode* recurFunc(vector<int>& inorder, vector<int>& postorder, int &ind, int left, int right) {
        if(left>right)
            return NULL;
        int curr = postorder[ind--];
        TreeNode* temp = new TreeNode(curr);
        if(left == right)
            return temp;
        int lim = umap[curr];
        temp->right = recurFunc(inorder, postorder, ind, lim+1, right);
        temp->left = recurFunc(inorder, postorder, ind, left, lim-1);
        return temp;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int isize = inorder.size();
        for(int i=0;i<isize;i++){
            umap[inorder[i]] = i;
        }
        int ind = isize-1;
        return recurFunc(inorder, postorder, ind, 0, isize-1);
    }
};

int main(){
    Solution S;
    int N = -1;
    vector<int> post = {9,15,7,20,3};
    vector<int> in = {9,3,15,20,7};
    TreeNode* ans = S.buildTree(in, post);
    S.printTree(ans);
}
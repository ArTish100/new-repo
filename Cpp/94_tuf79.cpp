//Morris Traversal
//94. Binary Tree Inorder Traversal
//114. Binary Tree Preorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp = root;
        TreeNode* prev;
        while(temp!=NULL){
            if(temp->left == NULL){
                ans.push_back(temp->val);
                temp = temp->right;
            }else{
                prev = temp->left;
                while(prev->right && prev->right!=temp)
                    prev = prev->right;
                if(prev->right == NULL){
                    prev->right = temp;
                    temp = temp->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(temp->val);
                    temp = temp->right;
                }
            }
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp = root;
        TreeNode* prev;
        while(temp!=NULL){
            if(temp->left == NULL){
                ans.push_back(temp->val);
                temp = temp->right;    
            }else{
                
                prev = temp->left;
                while(prev->right && prev->right != temp){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = temp;
                    ans.push_back(temp->val);
                    temp = temp->left;
                }else{
                    prev->right = NULL;
                    temp = temp->right;
                }
            }
        }
        return ans;
    } 
    
};

int main(){
    Solution S;
    int N = -1;
    vector<int> vec = {1,2,3,4,5,N,8,N,N,6,7,N,N,9,N};
    TreeNode* root = S.constructTree(vec);
    S.printTree(root);
    S.printVecOfInt(S.inorderTraversal(root));
    cout<<"Preorder"<<endl;
    S.printVecOfInt(S.preorderTraversal(root));
}
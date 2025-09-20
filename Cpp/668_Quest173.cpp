//662. Maximum Width of Binary Tree

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
        if(i>=ans.size() || ans[i]==NULL)
            return NULL;
        TreeNode* root = new TreeNode(ans[i]);
        root->left = recurConstTree(ans,(2*i)+1);
        root->right = recurConstTree(ans,(2*i)+2);
        return root;
    }

    TreeNode* constructBST(vector<int> ans){
        TreeNode* root = recurConstTree(ans, 0);
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
            cout<<b<<endl;
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        // If the root is null,
        // the width is zero
        if (!root) {
            return 0;
        }

        // Initialize a variable 'ans'
        // to store the maximum width
        int ans = 0;

        // Create a queue to perform level-order
        // traversal, where each element is a pair
        // of TreeNode* and its position in the level
        queue<pair<TreeNode*, int>> q;
        // Push the root node and its
        // position (0) into the queue
        q.push({root, 0});

        // Perform level-order traversal
        while (!q.empty()) {
            // Get the number of
            // nodes at the current level
            int size = q.size();
            // Get the position of the front
            // node in the current level
            int mmin = q.front().second;
            
            // Store the first and last positions 
            // of nodes in the current level
            int first, last;

            // Process each node
            // in the current level
            for (int i = 0; i < size; i++) {
                // Calculate current position relative
                // to the minimum position in the level
                int cur_id = q.front().second - mmin;
                // Get the current node
                TreeNode* node = q.front().first;
                // Pop the front node from the queue
                q.pop();

                // If this is the first node in the level, 
                // update the 'first' variable
                if (i == 0) {
                    first = cur_id;
                }

                // If this is the last node in the level,
                // update the 'last' variable
                if (i == size - 1) {
                    last = cur_id;
                }

                // Enqueue the left child of the 
                // current node with its position
                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }

                // Enqueue the right child of the
                // current node with its position
                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }

            // Update the maximum width by calculating
            // the difference between the first and last
            // positions, and adding 1
            ans = max(ans, last - first + 1);
        }

        // Return the maximum
        // width of the binary tree
        return ans;
    }
    int widthOfBinaryTree1(TreeNode* root){
        int ans=0;
        queue<pair<int,TreeNode*>> qtree;
        qtree.push({0,root});
        pair<int,TreeNode*> temp;
        int t;
        int qsize;
        int first_node;
        int last_node;
        int curr;
        while(!qtree.empty()){
            qsize=qtree.size();
            t = qtree.front().first;
            for(int i=0;i<qsize;i++){
                temp = qtree.front();
                curr = qtree.front().first-t;
                cout<<curr<<endl;
                qtree.pop();
                if(i==0)
                    first_node = curr;
                if(i==qsize-1)
                    last_node = curr;
                if(temp.second->left)
                    qtree.push({2*curr+1,temp.second->left});
                if(temp.second->right)
                    qtree.push({2*curr+2,temp.second->right});                    
            }
            ans = max(ans, last_node-first_node+1);
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> vec = {1,3,2,5,NULL,NULL,9,6,NULL,7,NULL};
    TreeNode* root = S.constructBST(vec);
    cout<<S.widthOfBinaryTree(root);
}
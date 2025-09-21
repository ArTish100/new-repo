//Minimum time taken to BURN the Binary Tree from a Node

//863. All Nodes Distance K in Binary Tree

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
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
    int minTime(TreeNode* root, int target) {
        if(!root->left && !root->right)
            return 0;
        int ans = 0;
        queue<TreeNode*> qtree;
        qtree.push(root);
        TreeNode* temp;
        TreeNode* tnode;
        unordered_map<TreeNode*,TreeNode*> treemp;
        int qsize;
        while(!qtree.empty()){
            qsize = qtree.size();
            for(int i=0;i<qsize;i++){
                temp = qtree.front();
                qtree.pop();
                if(target == temp->val)
                    tnode = temp;
                if(temp->left){
                    treemp[temp->left] = temp;
                    qtree.push(temp->left);
                }
                if(temp->right){
                    treemp[temp->right] = temp;
                    qtree.push(temp->right);
                }
            }
        }
        qtree.push(tnode);
        unordered_set<TreeNode*> visited;
        while(!qtree.empty()){
            qsize = qtree.size();
            ans+=1;
            // cout<<"qsize : "<<qsize<<endl;
            for(int i=0;i<qsize;i++){
                temp = qtree.front();
                visited.insert(temp);
                qtree.pop();
                // cout<<temp->val<<" ";
                if(temp->left && !visited.count(temp->left))
                    qtree.push(temp->left);
                if(temp->right && !visited.count(temp->right))
                    qtree.push(temp->right);
                if(treemp.find(temp)!=treemp.end() && !visited.count(treemp[temp]))
                    qtree.push(treemp[temp]);
            }
            // cout<<endl;
            // cout<<"cross"<<endl;
            
        }
        return ans-1;
    }
};

int main(){
    Solution S;
    int N = -1;
    vector<int> vec = {1, 2, 3, 4, 5, N, 7, 8, N, 10};
    TreeNode* root = S.constructTree(vec);
    S.printTree(root);
    cout<<S.minTime(root,10);
}
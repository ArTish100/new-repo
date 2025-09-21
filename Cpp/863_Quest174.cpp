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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
            return {target->val};
        queue<TreeNode*> qtree;
        qtree.push(root);
        TreeNode* temp;
        TreeNode* tnode;
        int qsize;
        unordered_map<TreeNode*,TreeNode*> treemp;
        while(!qtree.empty()){
            qsize = qtree.size();
            for(int i=0;i<qsize;i++){
                temp = qtree.front();
                qtree.pop();
                if(temp == target)
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
        int dist = 0;
        unordered_set<TreeNode*> visited;
        while(!qtree.empty()){
            qsize = qtree.size();
            for(int i=0;i<qsize;i++){
                temp = qtree.front();
                // cout<<temp->val<<" ";
                qtree.pop();
                visited.insert(temp);
                if(temp->left && !visited.count(temp->left))
                    qtree.push(temp->left);
                if(temp->right && !visited.count(temp->right))
                    qtree.push(temp->right);
                if(treemp.find(temp)!=treemp.end() && !visited.count(treemp[temp])){
                    qtree.push(treemp[temp]);
                }
            }
            // cout<<endl;
            dist+=1;
            // cout<<"dist "<<dist<<endl;
            if(dist==k)
                break;
        }
        qsize = qtree.size();
        vector<int> ans;
        while(!qtree.empty()){
            ans.push_back(qtree.front()->val);
            qtree.pop();
        }
        return ans;
    }
};

int main(){
    Solution S;
    int N = -1;
    vector<int> vec = {3,5,1,6,2,0,8,N,N,7,4};
    TreeNode* root = S.constructTree(vec);
    S.printTree(root);
    S.printVecOfInt(S.distanceK(root,root->left,2));
}
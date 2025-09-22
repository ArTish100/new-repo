//297. Serialize and Deserialize Binary Tree

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
    string serialize(TreeNode* root) {
        queue<TreeNode*> qtree;
        qtree.push(root);
        TreeNode* temp;
        int qsize;
        int count;
        string data="";
        while(!qtree.empty()){
            temp = qtree.front();
            qtree.pop();
            if(temp==NULL)
                data+="#,";
            else{
                data+=to_string(temp->val)+',';
                qtree.push(temp->left);
                qtree.push(temp->right);
            }
            
        }
        return data;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> qtree;
        stringstream d(data);
        string nodeData;
        getline(d, nodeData, ',');
        TreeNode* root = new TreeNode(stoi(nodeData));
        qtree.push(root);
        TreeNode* temp;
        while(!qtree.empty()){
            temp = qtree.front();
            qtree.pop();
            getline(d, nodeData, ',');
            if(nodeData != "#"){
                temp->left = new TreeNode(stoi(nodeData));
                qtree.push(temp->left);
            }
            getline(d, nodeData, ',');
            if(nodeData != "#"){
                temp->right = new TreeNode(stoi(nodeData));
                qtree.push(temp->right);
            }
        }
        return root;
    }
};

int main(){
    Solution S;
    int N = -1;
    vector<int> vec = {1,2,3,N,N,6};
    TreeNode* root = S.constructTree(vec);
    S.printTree(root);
    TreeNode* ans = S.deserialize(S.serialize(root));
    S.printTree(ans);
}
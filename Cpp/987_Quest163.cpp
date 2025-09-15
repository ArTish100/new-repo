//987. Vertical Order Traversal of a Binary Tree

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
        if(i>=ans.size() || ans[i] == NULL)
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

    void intprintAns(vector<vector<int>> ans){
        for(auto b : ans){
            for(int a : b){
                cout<<a<<" "<<endl;
            }
            cout<<endl;
            // cout<<b<<endl;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)
            return {{}};
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> qtree;
        qtree.push({root,{0,0}});
        pair<TreeNode*,pair<int,int>> tempair;
        map<int,map<int,multiset<int>>> mptree;
        TreeNode* temp;
        int x,y;
        while(!qtree.empty()){
            tempair = qtree.front();
            qtree.pop();
            temp = tempair.first;
            x = tempair.second.first;
            y = tempair.second.second;
            mptree[x][y].insert(temp->val);
            if(temp->left){
                qtree.push({temp->left,{x-1,y+1}});
            }
            if(temp->right){
                qtree.push({temp->right,{x+1,y+1}});
            }
        }
        vector<int> dstr;
        for(auto a : mptree){
            for(auto b : a.second){
                dstr.insert(dstr.end(),b.second.begin(),b.second.end());
            }
            ans.push_back(dstr);
            dstr.clear();
        }
        return ans;
    }
};

int main(){
    Solution S;
    int N = NULL;
    vector<int> vec = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = S.constructTree(vec);
    vector<vector<int>> ans;
    ans = S.verticalTraversal(root);
    S.intprintAns(ans);
}
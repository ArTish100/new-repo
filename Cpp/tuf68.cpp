//Top view of a Binary Tree

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

    void intprintAns(vector<int> ans){
        for(auto b : ans){
            // for(int a : b){
            //     cout<<a<<" "<<endl;
            // }
            // cout<<endl;
            cout<<b<<endl;
        }
    }
    vector<int> topViewBinTree(TreeNode* root){
        if(!root)
            return {};
        vector<int> ans;
        queue<pair<TreeNode*,int>> qtree;
        pair<TreeNode*,int> tempair;
        TreeNode* temp;
        qtree.push({root,0});
        int x, y;
        map<int,int> mtree; 
        while(!qtree.empty()){
            tempair = qtree.front();
            qtree.pop();
            temp = tempair.first;
            x = tempair.second;
            if(mtree.find(x)==mtree.end())
                mtree[x] = temp->val;
            if(temp->left){
                qtree.push({temp->left,x-1});
            }
            if(temp->right){
                qtree.push({temp->right,x+1});
            }
        }
        for(auto a : mtree){
            ans.push_back(a.second);
        }
        return ans;
    }
};

int main(){
    Solution S;
    int N = NULL;
    vector<int> vec = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = S.constructTree(vec);
    vector<int> ans;
    ans = S.topViewBinTree(root);
    S.intprintAns(ans);
}
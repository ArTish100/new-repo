//Ceil in BST
//Floor in BST

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
    
    void findCeil(TreeNode* root, int x, int &val) {
        if(!root)
            return;
        if(x>root->val){
            findCeil(root->right, x, val);
        }else if(x<=root->val){
            val = root->val;
            findCeil(root->left, x, val);
        }
    }
    int findCeil(TreeNode* root, int x) {
        int ans = -1;
        findCeil(root, x, ans);
        return ans;
    }
    void findFloor(TreeNode* root, int x, int &ans) {
        if(!root)
            return;
        if(x<root->val){
            findFloor(root->left, x, ans);
        }else if(x>=root->val){
            ans = root->val;
            findFloor(root->right, x, ans);
        }
    }
    int floor(TreeNode* root, int x) {
        int ans = -1;
        findFloor(root, x, ans);
        return ans;
    }

};

int main(){
    Solution S;
    // int N = NULL;
    vector<int> vec = {5, 4, 6, 3, 7, 1};
    TreeNode* root = S.constructBST(vec);
    int ceil;
    ceil=S.findCeil(root,8);
    cout<<"ceil : "<<ceil;
}
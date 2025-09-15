//701. Insert into a Binary Search Tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        TreeNode* itr = root;
        while(!itr){
            if(val>itr->val){
                if(!itr->right){
                    itr->right = temp;
                    break;
                }
                itr = itr->right;
            }
            if(val<itr->val){
                if(!itr->left){
                    itr->left = temp;
                    break;
                }
                itr = itr->left;
            }
        }
        return root;
    }

};

int main(){
    Solution S;
    // int N = NULL;
    vector<int> vec = {5, 4, 6, 3, 7, 1};
    TreeNode* root = S.constructBST(vec);
    TreeNode* ceil;
    ceil=S.insertIntoBST(root,8);
    cout<<"ceil : "<<ceil;
}
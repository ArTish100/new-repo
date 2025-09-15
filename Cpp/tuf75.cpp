//Merge 2 BST's

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
    void inorderTraversal(TreeNode* root, vector<int> &ans){
        if(!root)
            return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
        return;
    }
    vector<int> merge(TreeNode *root1, TreeNode *root2) {
        vector<int> ans1;
        vector<int> ans2;
        inorderTraversal(root1, ans1);
        inorderTraversal(root2, ans2);
        int n1 = ans1.size();
        int n2 = ans2.size();
        vector<int> ans(n1+n2);
        int i=0,j=0,k=0;
        while(n1>i && n2>j){
            if(ans1[i]<=ans2[j]){
                ans[k]=(ans1[i]);
                k+=1;
                i++;
            }else{
                ans[k]=(ans2[j]);
                k+=1;
                j++;
            }
        }
        if(i<n1){
            while(i<n1){
                ans[k]=(ans1[i]);
                k+=1;
                i++;
            }
        }
        if(j<n2){
            while(j<n2){
                ans[k]=(ans2[j]);
                k+=1;
                j++;
            }
        }
        return ans;
    }
};

int main(){
    Solution S;
    // int N = NULL;
    vector<int> vec = {5, 3, 6, 2, 4};
    vector<int> vec1 = {2, 1, 3, 7, 6};
    TreeNode* root = S.constructBST(vec);
    TreeNode* root1 = S.constructBST(vec1);
    vector<int> ceil;
    ceil=S.merge(root, root1);
    S.intprintAns(ceil);
}
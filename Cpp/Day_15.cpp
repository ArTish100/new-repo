#include<iostream>
#include<vector>
#include<queue>
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
    vector<int> rightSideView(TreeNode* root) {
        cout<<"works";
        vector<int> ans;
        if(root==NULL)
            return ans;
        vector<TreeNode*> queue1;
        vector<int> qheight;
        int height=-1;
        qheight.push_back(height);
        queue1.push_back(root);
        ans.push_back(root->val);
        cout<<"works";
        while(!queue1.empty()){
            TreeNode* temp=new TreeNode;
            temp=queue1.back();
            if(qheight.back()>height){
                height++;
                ans.push_back(temp->val);
            }
            
            queue1.pop_back();
            if(temp->left!=NULL){
                queue1.push_back(temp->left);
                qheight.push_back(qheight.back()+1);
            }
            if(temp->right!=NULL){
                queue1.push_back(temp->right);
                qheight.push_back(qheight.back()+1);
            }
            qheight.pop_back();
        }
        return ans;
    }
};
int main(){
    TreeNode* head=new TreeNode(4);
    head=new TreeNode(3,NULL,head);
    TreeNode* temp=new TreeNode(5);
    temp=new TreeNode(2,NULL,temp);
    head=new TreeNode(1,temp,head);
    Solution S;
    vector<int> ans=S.rightSideView(head);
    int vsize=ans.size();
    for(int i=0;i<vsize;i++){
        cout<<ans[i]<<" ";
    }
}
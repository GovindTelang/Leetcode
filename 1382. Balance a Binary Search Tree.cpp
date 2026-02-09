/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode * root,vector<int> &ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* balanceBST(TreeNode* root) {
      vector<int> ans; 
      inorder(root,ans);
      TreeNode * hex = form(ans,0,ans.size());
      return hex;  
    }
    TreeNode* form(vector<int> &ans,int l,int r){
    if(l==r) return NULL;
    int m = (l+r-1)/2;
    TreeNode * root = new TreeNode(ans[m]);
    root->left = form(ans,l,m);
    root->right = form(ans,m+1,r);
    return root;
    }
};

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
    bool isEvenOddTree(TreeNode* root) {
        bool even = 1;
        queue<TreeNode *> q;
        q.push(root);
       
        while(!q.empty()){
            int sz = q.size();
            int prev = INT_MAX;
            if(even){
             prev = INT_MIN;
            }
            for(int i=0;i<sz;i++){
                TreeNode * curr = q.front();
                q.pop();
                if((even && (curr->val%2==0 || curr->val <= prev)) || (!even &&(curr->val%2 || curr->val >= prev))) return false;
                prev=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            even = !even;
        }
        return true;
    }
};

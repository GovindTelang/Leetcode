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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
        long long size = q.size();
        long long sum = 0;
        for(long long i=0;i<size;i++){
        TreeNode * curr = q.front();
        q.pop();
        sum += curr->val;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        }
        pq.push(sum);
        if(pq.size()>k){
            pq.pop();
        }
        }
        return pq.size()<k ? -1 : pq.top();
    }
};

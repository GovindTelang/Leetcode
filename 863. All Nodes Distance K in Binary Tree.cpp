/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     unordered_map<TreeNode *,TreeNode*> parent_track;
     unordered_map<TreeNode *,bool> vis;
     queue<TreeNode *> q;
     q.push(root);
     while(!q.empty()){
        TreeNode * curr = q.front();
        q.pop();
        if(curr->left){
            parent_track[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right]=curr;
            q.push(curr->right);
        }
     }
     q.push(target);
     vis[target]=true;
     int curr_level = 0;
     while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k) break;
        for(int i=0;i<size;i++){
            TreeNode * x = q.front();
            q.pop();
            if(x->left && !vis[x->left]){
                vis[x->left]=true;
                q.push(x->left);
            }
            if(x->right && !vis[x->right]){
                vis[x->right]=true;
                q.push(x->right);
            }
            if(parent_track[x] && !vis[parent_track[x]]){
                vis[parent_track[x]]=true;
                q.push(parent_track[x]);
            }
        }
     }
     vector<int> ans;
     while(!q.empty()){
        TreeNode * current=q.front();
        q.pop();
        ans.push_back(current->val);
     }
     return ans;
    }
};

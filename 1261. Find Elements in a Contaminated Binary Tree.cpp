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
class FindElements {
public:
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        return seen.count(target)>0;
    }

private:
    unordered_set<int> seen;

    void dfs(TreeNode* currentNode,int currentValue){
        if(!currentNode) return;
        seen.insert(currentValue);
        dfs(currentNode->left,currentValue*2+1);
        dfs(currentNode->right,currentValue*2+2);
    }

};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

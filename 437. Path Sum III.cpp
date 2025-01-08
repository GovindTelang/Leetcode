class Solution {
public:
    int dfs(TreeNode* root,long long currsum,int targetSum,unordered_map<long long,int> &mp){
        if(!root) return 0;
        currsum += root->val;   // Update the current cumulative sum
        // Find the number of paths that sum to targetSum
        int count = mp[currsum-targetSum];
        // Update the hash map with the current cumulative sum
        mp[currsum]++;
        //go to left and right subtrees
        count += dfs(root->left,currsum,targetSum,mp);
        count += dfs(root->right,currsum,targetSum,mp);
        // Backtrack: remove the current sum from the hash map
    /*  5
       / \
      4   8
     /   / \
    11  13  4
   /  \      \
  7    2      1   after returning to 11 we do mp[27]-- so that we dont get any false positives */ 

        mp[currsum]--;
        return count;
    } 
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;  // Hash map to store cumulative sums
        mp[0]=1;     // Initialize with 0 sum having one path starting at root
        return dfs(root,0,targetSum,mp);
    }
};

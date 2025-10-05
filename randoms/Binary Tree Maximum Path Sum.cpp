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
    int maxSum = INT_MIN;  // global variable to track maximum path sum

    int dfs(TreeNode* root) {
        if (!root) return 0; // base case

        // recursively get max path sum of left and right subtree
        int left = max(dfs(root->left), 0);   // ignore negative sums
        int right = max(dfs(root->right), 0);

        // max path passing through current node
        int currentPath = root->val + left + right;

        // update global answer
        maxSum = max(maxSum, currentPath);

        // return max path going downward
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

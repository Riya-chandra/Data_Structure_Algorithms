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
int M=1e9+7;
long long totalSum=0;
long long bestProduct=0;
long long dfs(TreeNode* root){
    if(!root) return 0;
    long long left=dfs(root->left);
    long long right=dfs(root->right);

    long long subTreeSum=root->val+left+right;
    long long product=subTreeSum*(totalSum-subTreeSum);
    bestProduct=max(bestProduct,product);
    return subTreeSum;
}
    int maxProduct(TreeNode* root) {
        totalSum= dfsTotal(root);//pure ka sum mil gya now we pass root to dfs to cal each node ka mulitplacation
        dfs(root);
        return bestProduct % M;
    }
    long long dfsTotal(TreeNode* root){
        if(!root) return 0;
        return root->val+dfsTotal(root->left)+dfsTotal(root->right);
    }
};

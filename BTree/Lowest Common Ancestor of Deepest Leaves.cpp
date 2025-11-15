/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };// linkedlist hence no following of rule ki 2*i+1 or whatveer
 */
class Solution {
public:
pair<TreeNode* , int>dfs(TreeNode* root){
    vector<int> s;//that contains the node which are the deepest common ansestor 

        if(!root) return{NULL,0}; //having first is the node and the second is the depth 

        auto left=dfs(root->left);
        auto right=dfs(root->right);

        if(left.second==right.second)  //mtlb agr deth ki value dono ki same hogi toh 
        {
            return {root,left.second+1}; //uske root k liye upr chli jaow and depth +1 kr do 

        }
        if(left.second>right.second){
            return {left.first,left.second+1};
        }

        return {right.first,right.second+1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      return dfs(root).first;
    }
};
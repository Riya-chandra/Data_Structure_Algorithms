class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> que;
        vector<int> result;
        
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();
            TreeNode* rightNode = NULL;
            while(n--) {
                rightNode = que.front();
                que.pop();
                
                if(rightNode->left)
                    que.push(rightNode->left);
                if(rightNode->right)
                    que.push(rightNode->right);
            }
            result.push_back(rightNode->val);
        }
        return result;
    }
};
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
    unordered_map<int, vector<int>> adj; // adjacency list

    // Build graph from tree
    void buildGraph(TreeNode* node, TreeNode* parent) {
        if(!node) return;
        if(parent) {
            adj[node->val].push_back(parent->val);
            adj[parent->val].push_back(node->val);
        }
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }

    int amountOfTime(TreeNode* root, int start) {
       
        buildGraph(root, nullptr);
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        int minutes = -1;

        while(!q.empty()) {
            int sz = q.size();
            minutes++; // each level = 1 minute
            for(int i = 0; i < sz; i++) {
                int node = q.front(); q.pop();
                for(int nei : adj[node]) {
                    if(visited.find(nei) == visited.end()) {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }

        return minutes;
    }
};

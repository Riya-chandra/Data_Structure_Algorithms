class Codec {
public:
    // Serialize: Tree ko string banata hai (preorder traversal)
    string serialize(TreeNode* root) {
        string out;
        dfsSerialize(root, out);
        return out;
    }

    void dfsSerialize(TreeNode* node, string &out) {
        if (!node) {                     // agar node NULL hai
            out += "null,";              // null likho string me
            return;
        }
        out += to_string(node->val) + ","; // node ki value likho
        dfsSerialize(node->left, out);     // left child traverse karo
        dfsSerialize(node->right, out);    // right child traverse karo
    }

    // Deserialize: string ko wapas tree me convert karta hai
    TreeNode* deserialize(const string &data) {
        vector<string> tokens = split(data, ','); // string ko tod do
        int idx = 0; // current position
        return dfsDeserialize(tokens, idx);
    }

    TreeNode* dfsDeserialize(const vector<string> &tokens, int &idx) {
        if (idx >= tokens.size()) return nullptr;
        
        if (tokens[idx] == "null") { // agar null mila
            idx++;
            return nullptr;
        }

        int val = stoi(tokens[idx++]);   // string → number convert
        TreeNode* node = new TreeNode(val);
        node->left = dfsDeserialize(tokens, idx);   // left banate hain
        node->right = dfsDeserialize(tokens, idx);  // right banate hain
        return node;
    }

    // Helper: string ko ',' pe split karne ke liye
    vector<string> split(const string &s, char delim) {
        vector<string> res;
        string token;
        istringstream ss(s);
        while (getline(ss, token, delim)) {
            if (!token.empty()) res.push_back(token);
        }
        return res;
    }
};

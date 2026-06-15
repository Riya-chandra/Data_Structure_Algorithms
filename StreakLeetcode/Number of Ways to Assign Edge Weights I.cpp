class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b % 2)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b /= 2;
        }

        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = 0;

        function<void(int,int,int)> dfs = [&](int node,
                                              int parent,
                                              int depth) {
            maxDepth = max(maxDepth, depth);

            for (int nbr : adj[node]) {
                if (nbr == parent)
                    continue;

                dfs(nbr, node, depth + 1);
            }
        };

        dfs(1, 0, 0);

        if (maxDepth == 0)
            return 0;

        return power(2, maxDepth - 1);
    }
};

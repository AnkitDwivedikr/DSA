class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), tree(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> mp(26, -1);
        vector<int> newParent = parent;

        function<void(int)> dfs = [&](int node) {
            int ch = s[node] - 'a';

            if(mp[ch] != -1) {
                newParent[node] = mp[ch];
            }

            int old = mp[ch];
            mp[ch] = node;

            for(int child : adj[node]) {
                dfs(child);
            }

            mp[ch] = old;
        };

        dfs(0);

        for(int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<int(int)> solve = [&](int node) {
            for(int child : tree[node]) {
                ans[node] += solve(child);
            }

            return ans[node];
        };

        solve(0);

        return ans;
    }
};//akd
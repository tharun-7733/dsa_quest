class Solution {
public:
    void dfs(int node, unordered_set<int> &st,
                vector<vector<int>> &adjList, vector<int> &vis) {
        vis[node] = true;
        st.insert(node);

        for (auto &e : adjList[node]) {
            if (!vis[e]) {
                dfs(e, st, adjList, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        if (invocations.empty()) {
            vector<int> res;
            for (int i = 0; i < n; i++) {
                if (i != k) res.push_back(i);
            }

            return res;
        }

        vector<vector<int>> adjList(n);
        for (auto &e : invocations) {
            adjList[e[0]].push_back(e[1]);
        }

        unordered_set<int> st;
        st.insert(k);

        vector<int> vis(n, false);
        dfs(k, st, adjList, vis);

        if (st.size() == n) return {};

        for (int u = 0; u < adjList.size(); u++) {
            vector<int> ans;
            for (auto &v : adjList[u]) {
                if (!st.count(u) && st.count(v)) {
                    for (int i = 0; i < n; i++) {
                        ans.push_back(i);
                    }
                    return ans;
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!st.count(i)) res.push_back(i);
        }
        
        return res;
    }
};
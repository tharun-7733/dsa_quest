class Solution {
public: 
    vector<int> parent;
    int find(int x) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);

        if(x_p != y_p) {
            parent[x_p] = y_p;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &e : edges) {
            Union(e[0], e[1]);
        }

        unordered_map<int, int> vertex;
        unordered_map<int, int> edgeCnt;


        int count = 0;

        // count vertexes
        for(int i = 0; i < n; i++) {
            vertex[find(i)]++;
        }

        // count edges
        for(auto &e : edges) {
            edgeCnt[parent[e[0]]]++;
        }

        for(auto &[root, v] : vertex) {
            int EdgeCount = (v * (v - 1)) / 2;

            if(edgeCnt[root] == EdgeCount) count++;
        }
        return count;
    }
};
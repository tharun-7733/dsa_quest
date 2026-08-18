class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adjList(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], time = e[2];

            adjList[u].push_back({time, v});
            adjList[v].push_back({time, u});
        }

        vector<vector<int>> dist(n + 1, vector<int> (maxTime + 1, INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({passingFees[0], {0, 0}});
        dist[0][0] = passingFees[0];

        while (!pq.empty()) {
            auto current = pq.top(); pq.pop();
            int cost = current.first;
            int time = current.second.first;
            int node = current.second.second;

            if (cost != dist[node][time]) continue;

            if (node == n - 1) return cost;

            for (auto &p : adjList[node]) {
                int tm = p.first;
                int nd = p.second;

                int newTime = tm + time;

                if (newTime > maxTime) continue;

                int newCost = cost + passingFees[nd];

                if (newCost < dist[nd][newTime]) {
                    dist[nd][newTime] = newCost;
                    pq.push({newCost, {newTime, nd}});
                }
            }
        }

        return -1;
    }
};
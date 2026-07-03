class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> adjList;
    bool check(int mid, vector<bool> &online, long long k) {

        priority_queue<pair<long long, int>, 
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        int Min = INT_MAX;
        vector<int> ele;
        while(!pq.empty()) {
            auto [weight, node] = pq.top(); pq.pop();

            if(weight != dist[node]) continue;

            for (auto &[wt, nei] : adjList[node]) {
                if(nei != n - 1 && !online[nei]) continue;

                if(wt < mid) continue;
                
                if(dist[node] + wt < dist[nei]) {
                    dist[nei] = dist[node] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        return dist[n - 1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        this -> n = online.size();
        adjList.resize(n);
        int low = 0, high = 0;
        for(auto &e : edges) {
            adjList[e[0]].push_back({e[2], e[1]});
            high = max(high, e[2]);
        }
        
        int ans = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(mid, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
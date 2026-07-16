class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        double sq = 0.0;

        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            sq = sqrt((x * x) + (y * y));

            pq.push({sq, i});

            if(pq.size() > k) pq.pop();
        }

        vector<int> indexes;
        while (!pq.empty()) {
            indexes.push_back(pq.top().second);
            pq.pop();
        }

        vector<vector<int>> ans;
        for(auto &i : indexes) {
            ans.push_back(points[i]);
        }

        return ans;
    }
};
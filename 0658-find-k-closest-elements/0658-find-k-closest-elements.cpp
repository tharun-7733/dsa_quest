class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            pq.push({abs(arr[i] - x), arr[i]});
            while (pq.size() > k) pq.pop();
        }

        while (!pq.empty()) {
            auto [firstDist, first] = pq.top(); pq.pop();
            ans.push_back(first); 
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
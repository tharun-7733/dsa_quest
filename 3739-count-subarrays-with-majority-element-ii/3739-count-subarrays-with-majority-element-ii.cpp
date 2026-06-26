class Solution {
public:
    /*
    Fenwick Tree which helps in optimal returving of the element using query and update in log n
    */

    int bit[100001];
    int n;
    void update(int idx) {
        while(idx <= n) {
            bit[idx]++;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        this -> n = nums.size();

        for(int i = 0; i < n; i++) {
            nums[i] = (nums[i] == target) ? 1 : -1;
        }

        vector<int> prefix(n + 1);
        prefix[0] = 0;

        for(int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        vector<int> values = prefix;
        unordered_map<int, int> Rank;

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        for(int i = 0; i < values.size(); i++) {
            Rank[values[i]] = i + 1;
        }

        long long count = 0;
        update(Rank[prefix[0]]);
        for(int i = 1; i < n + 1; i++) {
            int rank = Rank[prefix[i]];
            count += query(rank - 1);
            update(rank);
        }

        return count;
    }
};
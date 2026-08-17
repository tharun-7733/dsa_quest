class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp;
    int solve(int start, int end, vector<int> &stones) {
        int n = stones.size();
        if (start == end) return 0;
        
        if (dp[start][end] != -1) return dp[start][end];

        int l = 0, r = 0, alice = 0;
        for (int i = start; i < end; i++) {
            l = prefix[i + 1] - prefix[start];
            r = prefix[end + 1] - prefix[i + 1];

            if (l < r) {
                alice = max(alice, l + solve(start, i, stones));
            } else if (r < l) {
                alice = max(alice, r + solve(i + 1, end, stones));
            } else {
                    alice = max(alice, 
                        max(l + solve(start, i, stones), 
                        r + solve(i + 1, end, stones)));
            }
        }
        return dp[start][end] = alice;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        dp.resize(n + 1, vector<int> (n + 1, -1));

        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};
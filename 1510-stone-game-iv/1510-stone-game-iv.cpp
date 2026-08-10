class Solution {
public:
    vector<int> dp;
    bool solve(int n) {
        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        for (int j = 1; j * j <= n; j++) {
            if (!solve(n - j * j)) {
                return dp[n] = 1;
            }
        }

        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);

        return solve(n);
    }
};
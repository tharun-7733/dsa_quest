class Solution {
public:
    int solve(int idx, int turn, int m, vector<int> &piles, vector<vector<vector<int>>> &dp) {
        int n = piles.size();
        if (idx >= n) return 0;

        if (dp[idx][turn][m] != -1) return dp[idx][turn][m];

        int score = 0, best = (turn == 1) ? -1 : 1e9;
        for (int x = 1; x <= 2 * m && idx + x <= n; x++) {
            if (turn) {
                score += piles[idx + x - 1];
                best = max(
                    best, 
                    score + solve(idx + x, 0, max(x, m), piles, dp));
            } else {
                best = min(
                    best,
                    solve(idx + x, 1, max(x, m), piles, dp));
            }
        }

        return dp[idx][turn][m] = best;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (205, -1)));
        return solve(0, 1, 1, piles, dp);
    }
};
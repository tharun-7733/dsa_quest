class Solution {
public:
    // int solve(int n, int m, string t1, string t2, vector<vector<int>> &dp) {
    //     if (n == 0 || m == 0) return 0;

    //     if (dp[n - 1][m - 1] != -1) return dp[n - 1][m - 1];

    //     if (t1[n - 1] == t2[m - 1]) {
    //         return 1 + solve(n - 1, m - 1, t1, t2, dp);
    //     } else {
    //         dp[n - 1][m - 1] = max(solve(n - 1, m, t1, t2, dp), solve(n, m - 1, t1, t2, dp));
    //     }

    //     return dp[n - 1][m - 1];
    // }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.length(), m = t2.length();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }

        return dp[n][m];
    }
};
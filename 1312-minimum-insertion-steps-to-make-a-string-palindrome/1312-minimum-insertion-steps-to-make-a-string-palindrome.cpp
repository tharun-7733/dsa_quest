class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        if (n == 1) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for (int i = n - 2; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return n - dp[0][n - 1];
    }
};
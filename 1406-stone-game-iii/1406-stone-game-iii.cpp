class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, int turn, vector<int> &stones) {
        int n = stones.size();
        if (idx >= n) return 0;
        
        int score = 0;
        int best = (turn == 1) ? -1e9 : 1e9;

        if (dp[idx][turn] != -1e9) return dp[idx][turn];

        for (int i = 0; i < 3 && idx + i < n; i++) {
            score += stones[idx + i];

            if (turn) {
                best = max(best, 
                        score + solve(idx + i + 1, !turn, stones));
            } else {
                best = min(best, 
                            solve(idx + i + 1, !turn, stones));
            }
        }

        return dp[idx][turn] = best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        dp.assign(n + 1, vector<int> (2, -1e9));

        int alice = solve(0, 1, stoneValue);
        int bob = total - solve(0, 1, stoneValue);
        
        return (alice > bob) ? "Alice" : ((bob > alice) ? "Bob" : "Tie");
    }
};
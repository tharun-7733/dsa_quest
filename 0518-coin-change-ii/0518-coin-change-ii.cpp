class Solution {
public: 
    vector<vector<int>> dp;
    int solve(int i, int amount, vector<int>& coins) {
        int n = coins.size();


        if(amount == 0) return 1;

        if(i == n) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int skip = 0 + solve(i + 1, amount, coins);
        int take = 0;

        if(coins[i] <= amount) {
            take = solve(i, amount - coins[i], coins);
        }

        return dp[i][amount] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        dp.assign(n, vector<int> (amount + 1, -1));

        return solve(0, amount, coins);
    }
};
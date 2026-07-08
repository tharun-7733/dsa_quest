class Solution {
public:
    unordered_set<long long> s;
    unordered_map<long long, int> dp;
    int solve(int x) {
        if(dp.count(x)) return dp[x];

        if (!s.count(1LL * x * x)) {
            return dp[x] = 1;
        }

        return 1 + solve(1LL * x * x);
    }
    int longestSquareStreak(vector<int>& nums) {
        for(int x : nums) {
            s.insert(x);
        }

        int maxLen = -1;
        for(int i = 0; i < nums.size(); i++) {
            maxLen = max(maxLen, solve(nums[i]));
        }

        return maxLen >= 2 ? maxLen : -1;
    }
};
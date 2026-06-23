class Solution {
public:
    int n, total;
    int dp[1001][2001];
    int solve(int idx, int sum, vector<int> &nums, int target) {
        if(idx >= n) return sum == target;

        if(dp[idx][sum + total] != -1) return dp[idx][sum + total];

        int add = solve(idx + 1, sum + nums[idx], nums, target);
        int subtract = solve(idx + 1, sum - nums[idx], nums, target);

        return dp[idx][sum + total] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this -> n = nums.size();
        this -> total = accumulate(nums.begin(), nums.end(), 0);

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, nums, target);
    }
};
class Solution {
public:
    int dp[201][20001];
    int n;
    bool solve(int idx, int curSum, int total, vector<int>& nums) {
        if(idx == n) return curSum == total / 2;

        if(dp[idx][curSum] != -1) return dp[idx][curSum];

        bool take = solve(idx + 1, curSum + nums[idx], total, nums);
        bool skip = solve(idx + 1, curSum, total, nums);


        return dp[idx][curSum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        this -> n = nums.size();


        memset(dp, -1, sizeof(dp));

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total % 2 != 0) return false;

        return solve(0, 0, total, nums);
    }
};
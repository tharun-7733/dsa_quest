class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int longest = 0, streak = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                streak++;
            } else {
                streak = 1;
            }

            longest = max(longest, streak);
        }

        return (n == 1) ? 1 : longest;
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int Xor = 0;
        bool nonZero = 0;

        for (int right = 0; right < n; right++) {
            Xor ^= nums[right];

            if (Xor != 0) {
                nonZero = true;
            }
        }

        if (!nonZero) return 0;

        if (Xor != 0) return n;

        return n - 1;
    }
};
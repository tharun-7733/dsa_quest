class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        
        // condition 1 :- total xor value = 0 return 0;
        // condition 2 :- total xor value != 0 return n;
        // condition 3 :- total xor value zero but non zero xor value exist return n - 1
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
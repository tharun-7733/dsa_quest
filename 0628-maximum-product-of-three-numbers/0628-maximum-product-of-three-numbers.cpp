class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int product = nums[i] * nums[j] * nums[k];
                ans = max(ans, product);
                j++;
                k--;
            }
        }
        return ans;
    }
};
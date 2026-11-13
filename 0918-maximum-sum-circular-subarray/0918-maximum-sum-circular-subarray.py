class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        n = len(nums)

        cur_max, cur_min = 0, 0
        ans_max, ans_min = nums[0], nums[0]
        total_sum = 0

        for num in nums:
            total_sum += num

            cur_max = max(num, num + cur_max)
            ans_max = max(ans_max, cur_max)

            cur_min = min(num, num + cur_min)
            ans_min = min(ans_min, cur_min)

        if ans_max < 0:
            return ans_max

        return max(ans_max, total_sum - ans_min)
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        target = list(range(n))
        i = nums.index(0)
        # shift/reverse the array from 0 val index to match the target
        # reverse 0 val index left side and right side. Join both and match them
        # Try Rotate from 0 val index as well
        if nums[i:] + nums[:i] == target:
            return min(i, n - i + 2)
        if nums[i::-1] + nums[:i:-1] == target:
            return min(i + 2, n - i)
        
        return -1
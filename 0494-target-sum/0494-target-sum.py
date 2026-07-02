class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        total = sum(nums)

        dp = [[-1] * (2001) for _ in range(1001)]

        def solve(idx, CurSum) ->int:
            if idx >= n:
                return CurSum == target

            if dp[idx][CurSum + total] != -1:
                return dp[idx][CurSum + total]

            sub = solve(idx + 1, CurSum - nums[idx])
            add = solve(idx + 1, CurSum + nums[idx])

            dp[idx][CurSum + total] = (add + sub)
            return dp[idx][CurSum + total]

        return solve(0, 0)
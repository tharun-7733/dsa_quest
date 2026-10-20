class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)

        def solve(k):
            i = 0
            prev = 0
            while i < n:
                j = i + k

                part = nums[i:j]
                dec = 0
                for x in range(k):
                    if part[x] > part[(x + 1) % k]:
                        dec += 1

                if dec <= 1 and prev <= min(part):
                    i += k
                    prev = max(part)
                else:
                    return False
            
            return True

        k = 1
        result = 0
        while k * k <= n:
            if n % k == 0:
                if solve(k):
                    result += k
                
                if k * k != n and solve(n // k):
                    result += n // k

            k += 1
        
        return result

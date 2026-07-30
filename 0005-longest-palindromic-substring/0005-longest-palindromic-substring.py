class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        bestLen = 0
        res = ""
        
        def solve(l, r) -> int:
            nonlocal bestLen, res

            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > bestLen:
                    res = s[l:r + 1]
                    bestLen = r - l + 1

                l -= 1
                r += 1
            
            return bestLen

        for i in range(n):
            # odd length
            oddLen = solve(i, i)

            # even length
            evenLen = solve(i, i + 1)

        return res
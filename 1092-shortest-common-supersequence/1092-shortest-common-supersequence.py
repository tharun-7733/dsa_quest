class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)

        dp = [[0] * (m + 1) for _ in range(n + 1)]

        def solve() -> str:
            dp[0][0] = 0
            for i in range(1, n + 1):
                for j in range(1, m + 1):

                    if str1[i - 1] == str2[j - 1]:
                        dp[i][j] = 1 + dp[i - 1][j - 1]
                    else:
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            
            lcs = ""
            i, j = n, m

            while i > 0 and j > 0:

                if str1[i - 1] == str2[j - 1]:
                    lcs += (str1[i - 1])
                    i -= 1
                    j -= 1
                else:
                    if dp[i - 1][j] > dp[i][j - 1]:
                        i -= 1
                    else:
                        j -= 1
            lcs = lcs[::-1]
            return lcs
        lcs = solve()

        ans = ""
        p1, p2 = 0, 0

        for c in lcs:
            while p1 < n and str1[p1] != c:
                ans += str1[p1]
                p1 += 1
            
            while p2 < m and str2[p2] != c:
                ans += str2[p2]
                p2 += 1
            
            ans += c
            p1 += 1
            p2 += 1

        while p1 < n:
            ans += str1[p1]
            p1 += 1
        
        while p2 < m:
            ans += str2[p2]
            p2 += 1

        return ans
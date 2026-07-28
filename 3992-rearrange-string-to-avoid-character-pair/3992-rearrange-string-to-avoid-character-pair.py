class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        n = len(s)
        freq = Counter(s)
        ans = ""

        ans = y * freq[y]

        for i in range(n):
            if s[i] == y:
                continue
            else:
                ans += s[i]
        
        return ans
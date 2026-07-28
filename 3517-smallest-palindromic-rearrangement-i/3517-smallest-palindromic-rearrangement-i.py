class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)

        freq = Counter(s[:n >> 1])
        half = ""

        for i in ascii_lowercase:
            half += i * freq[i]

        mid = s[n >> 1] if n & 1 else ""

        return half + mid + half[::-1]
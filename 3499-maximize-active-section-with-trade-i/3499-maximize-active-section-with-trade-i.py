class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:

        cnt_freq = []
        ones = 0

        for i in range(len(s)):
            if s[i] == '1':
                ones += 1

        t = "1" + s + "1"
        n = len(t)

        # store the cnt of frequency of each element in array
        i = 0
        while i < n:
            j = i
            while j < n and t[i] == t[j]:
                j += 1

            cnt_freq.append((t[i], j - i))
            i = j

        best_gain = 0
        for i in range(1, len(cnt_freq) - 1):
            if (cnt_freq[i][0] == '1' and 
            cnt_freq[i - 1][0] == '0' and 
            cnt_freq[i + 1][0] == '0'):

                best_gain = max(best_gain, 
                                        cnt_freq[i - 1][1] + cnt_freq[i + 1][1])
        
        return ones + best_gain
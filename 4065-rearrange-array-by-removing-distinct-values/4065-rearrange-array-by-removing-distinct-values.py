from collections import Counter

class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        mp = Counter(nums)

        ans = []

        while mp:
            temp = sorted(mp.keys())

            for x in temp:
                ans.append(x)
                mp[x] -= 1

                if mp[x] == 0:
                    del mp[x]

        return ans
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        idx = list(range(len(arr)))
        idx = sorted(range(len(arr)), key= lambda i: arr[i])

        if len(arr) == 0:
            return []

        ranks = [0] * len(arr)

        rank = 1

        ranks[idx[0]] = rank

        for i in range(1, len(arr)):
            if arr[idx[i]] != arr[idx[i - 1]]:
                rank += 1
            
            ranks[idx[i]] = rank
        
        return ranks
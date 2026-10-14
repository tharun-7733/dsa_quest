class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        s = math.ceil(sum / 9)

        if sum > 9 * num:
            return ""

        result = ["0"] * num

        i = 0
        while sum > 0:
            result[i] = str(min(sum, 9))
            sum -= 9
            i += 1
        
        return "".join(result)

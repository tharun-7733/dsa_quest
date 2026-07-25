class Solution:
    maximum, Second_maximum = 0, -1
    def maxElement(self, last: int):
        if last > self.maximum:
            self.Second_maximum = self.maximum
            self.maximum = last
        elif last > self.Second_maximum:
            self.Second_maximum = last

    def maxProduct(self, n: int) -> int:
        while n > 0:
            last = n % 10
            self.maxElement(last)
            n //= 10
        
        return self.maximum * self.Second_maximum
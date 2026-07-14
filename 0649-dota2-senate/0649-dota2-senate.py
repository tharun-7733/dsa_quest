from collections import deque
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        Radiant = deque()
        Dire = deque()

        for i in range(len(senate)):
            if senate[i] == 'R':
                Radiant.append(i)
            else:
                Dire.append(i)
        
        while Radiant and Dire:
            d = Dire.popleft()
            r = Radiant.popleft()

            if r < d:
                Radiant.append(r + len(senate))
            elif d < r:
                Dire.append(d + len(senate))

        if len(Radiant) == 0:
            return "Dire"
        else:
            return "Radiant"
        
        return ""
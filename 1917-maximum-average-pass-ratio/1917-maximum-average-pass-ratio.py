from queue import PriorityQueue


class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extra: int) -> float:
        pq = PriorityQueue()

        for ele in classes:
            pq.put([-(1.0*(1+ele[0])/(1+ele[1]))+(1.0*ele[0]/ele[1]),ele[0],ele[1]])
        
        while extra > 0:
            extra  = extra - 1
            ele = pq.get()
            pq.put([-(1.0*(2+ele[1])/(2+ele[2]))+(1.0*(1+ele[1])/(1+ele[2])),1+ele[1],1+ele[2]])

        ans  = 0.0
        while not pq.empty():
            ele = pq.get()
            ans = ans + ele[1]/ele[2]
        
        return 1.0*ans/len(classes)

        
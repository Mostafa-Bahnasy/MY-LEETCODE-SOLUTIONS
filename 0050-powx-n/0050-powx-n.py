class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        ret = 1
        neg = (n<0)
        n = abs(n)
        while n > 0:
            if n%2==1:
                ret = ret * x
            x = x * x
            n = n/2
        if neg:
            ret = 1 / ret
        return ret
        
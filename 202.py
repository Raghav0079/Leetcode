'''Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.'''

class Solution(object):
    def isHappy(self,n):
        """
        :type n: int
        :rtype: bool
        """
        if n<=0:
            return False
        seen=set()
        while n!=1:
            if n in seen:
                return False
            seen.add(n)
            n=sum(int(i)**2 for i in str(n))
        return True
    
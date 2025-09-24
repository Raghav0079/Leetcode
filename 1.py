'''Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.'''

class Solution(object):
    def twoSum(self,num,target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(num)):
            for j in range(i+1,len(num)):
                if num[i]+num[j]==target:
                    return [i,j]

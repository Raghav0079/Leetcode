''' Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.'''

class Solution(object):
    def minSubArrayLen(self,target,nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        l=0
        r=0
        curr_sum=0
        min_len=float('inf')
        while r<n:
            curr_sum+=nums[r]
            while curr_sum>=target:
                min_len=min(min_len,r-l+1)
                curr_sum-=nums[l]
                l+=1
            r+=1
        return min_len if min_len!=float('inf') else 0
    
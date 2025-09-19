''' Given a string s, find the length of the longest substring without duplicate characters.'''

class Solution(object):
    def lengthOfLongestSubstring(self,s):
        """
        :type s: str
        :rtype: int
        """
        n=len(s)
        l=0
        r=0
        char_set=set()
        max_len=0
        while r<n:
            if s[r] not in char_set:
                char_set.add(s[r])
                max_len=max(max_len,r-l+1)
                r+=1
            else:
                char_set.remove(s[l])
                l+=1
        return max_len
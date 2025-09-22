''' Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.'''

class Solution(object):
    def isIsomorphic(self,s,t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_map={}
        t_map={}
        for i in range(len(s)):
            if s[i] not in s_map:
                s_map[s[i]]=t[i]
            if t[i] not in t_map:
                t_map[t[i]]=s[i]
            if s_map[s[i]]!=t[i] or t_map[t[i]]!=s[i]:
                return False
        return True
    
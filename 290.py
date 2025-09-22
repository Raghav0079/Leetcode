'''Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
'''

class Solution(object):
    def wordPattern(self,pattern,s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        words=s.split()
        if len(pattern) != len(words):
            return False
        p_map={}
        w_map={}
        for i in range(len(pattern)):
            if pattern[i] not in p_map:
                p_map[pattern[i]] = words[i]
            if words[i] not in w_map:
                w_map[words[i]] = pattern[i]
            if p_map[pattern[i]] != words[i] or w_map[words[i]] != pattern[i]:
                return False
        return True
    
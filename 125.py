''' A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.'''

class Solution(object):
    def isPalindrome(self,s):
        """
        :type s: str
        :rtype: bool
        """
        s = ''.join(e for e in s if e.isalnum()).lower()
        return s == s[::-1]
    

        
    
'''You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(cur,num):
            if not cur:
                return 0
            
            num = num * 10 +cur.val
            if not cur.left and not cur.right:
                return num
            
            return dfs(cur.left,num) + dfs(cur.right,num)
        
        return dfs(root,0)
        #   1
        # /   \
        #2     3
        
        # 0 * 10 + 1 = 1
        # 1 * 10 + 2 = 12
        # 1 * 10 + 3 = 13
    
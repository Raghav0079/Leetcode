''' Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.'''


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: bool
        """
        def dfs(curSum, node):
            if not node:
                return False
            curSum += node.val
            if not node.left and not node.right :
                return curSum == targetSum
            
            return (dfs(curSum, node.left) or
                    dfs(curSum, node.right))
            
        return dfs(0, root)
                
        
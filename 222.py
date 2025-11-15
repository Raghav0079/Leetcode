'''Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countNodes(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if not root:
            return 0
        
        def lheight(node):
            if not node :
                return 0
            return 1 + lheight(node.left)
        
        def rheight(node):
            if not node:
                return 0
            return 1 + rheight(node.right)
        
        l,r=lheight(root),rheight(root)
        
        if l>r:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)
        else:
            return (2 ** l) - 1
        
        
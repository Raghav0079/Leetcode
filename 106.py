''' Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: Optional[TreeNode]
        """
        inorderIdx={v:i for i , v in enumerate(inorder)}
        
        def helper(l,r):
            
            if l>r :
                return None
        
            root=TreeNode(postorder.pop())
        
            idx=inorderIdx[root.val]
            root.right =helper(idx+1,r)
            root.left =helper(l,idx-1)
            return root

        return helper(0,len(inorder)-1)
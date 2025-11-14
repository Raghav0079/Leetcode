'''Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

  '''
  
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        
        if not root:
            return None
        
        queue = deque([root])
        
        while queue:
            pre=None
            for _ in range(len(queue)):
                cur = queue.popleft()
                if pre:
                    pre.next = cur
                    
                if cur.left:
                    queue.append(cur.left)
                    
                if cur.right:
                    queue.append(cur.right)
                    
                pre = cur
                
        return root
        
            
    
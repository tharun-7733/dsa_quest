# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getSucc(self, node):
        node = node.right
        while node and node.left:
            node = node.left
        return node

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None

        # Search for an element in BST
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            # If node has 1 node
            if not root.left:
                return root.right
            if not root.right:
                return root.left
        
            # If node has 2 node
            succ = self.getSucc(root)

            root.val = succ.val
            root.right = self.deleteNode(root.right, succ.val)

        return root
        
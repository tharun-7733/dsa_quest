# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        def dfs(root) -> int:
            if not root:
                return 0
        
            l = dfs(root.left)
            r = dfs(root.right)

            if not root.left:
                return 1 + r
            if not root.right:
                return 1 + l

            return min(l, r) + 1

        return dfs(root)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []

        q = deque([(root, 0, 0)])

        nodes = defaultdict(lambda: defaultdict(list))

        while q:
            node, row, col = q.popleft()
            nodes[col][row].append(node.val)

            if node.left:
                q.append((node.left, row + 1, col - 1))
            if node.right:
                q.append((node.right, row + 1, col + 1))

        ans = []

        for col in sorted(nodes):
            cur = []
            for row in sorted(nodes[col]):
                cur.extend(sorted(nodes[col][row]))
            ans.append(cur)
        
        return ans
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    using Node = TreeNode;
public:
    Node* dfs(Node* root, Node* p, Node* q){
        if(!root) return nullptr;
        if(root -> val == p -> val || root -> val == q -> val){
            return root;
        }

        Node* l = dfs(root -> left, p, q);
        Node* r = dfs(root -> right, p, q);

        if(l && r) return root;
        else return l ? l : r;

        return dfs(root, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
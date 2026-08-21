/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(TreeNode* node, int targetSum) {
        if (!node) return ;

        temp.push_back(node -> val);

        if (!node -> left && !node -> right) {
            if (targetSum == node -> val) {
                ans.push_back(temp);
            }
                temp.pop_back();
                return ;
        }

        dfs(node -> left, targetSum - node -> val);
        dfs(node -> right, targetSum - node -> val);

        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};
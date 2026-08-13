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
    map<int, map<int, multiset<int>>> st;
    void dfs(TreeNode* root, int row, int col) {
        if (!root) return ;

        st[col][row].insert(root -> val);
        dfs(root -> left, row + 1, col - 1);
        dfs(root -> right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        dfs(root, 0, 0);

        for (auto &p : st) {
            vector<int> level;

            for (auto &i : p.second) {
                level.insert(level.end(), i.second.begin(), i.second.end());
            }

            ans.push_back(level);
        }

        return ans;
    }
};
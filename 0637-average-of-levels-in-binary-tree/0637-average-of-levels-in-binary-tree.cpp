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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> levels;

        queue<TreeNode*> q;
        q.push(root);

        if (!root) return levels;

        while (!q.empty()) {
            int sz = q.size();
            int total = q.size();
            double sum = 0;
            double average = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node -> left != nullptr) {
                    q.push(node -> left);
                }

                if (node -> right != nullptr) {
                    q.push(node -> right);
                }

                sum += node -> val;
            }
            levels.push_back((double)sum / total);
        }
        return levels;
    }
};
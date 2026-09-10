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



 // isBST, SUM, Min, Max
//  {1, 0, INT_MAX, INT_MIN}
class Solution {
public:
    vector<int> dfs(TreeNode* root, int &ans) {
        if (!root) return {1, 0, INT_MAX, INT_MIN};

        vector<int> l = dfs(root -> left, ans);
        vector<int> r = dfs(root -> right, ans);

        if (!l[0] || !r[0] || l[3] >= root -> val || r[2] <= root -> val) {
            return {0, 0, 0, 0};
        }

        int sum = l[1] + r[1] + root -> val;

        ans = max(sum, ans);

        return {1, sum, min(l[2], root -> val), max(r[3], root -> val)};
    }

    // bool check(TreeNode* root, int minVal, int maxVal) {
    //     if (!root) return true;

    //     if (root -> val <= minVal || root -> val >= maxVal) {
    //         return false;
    //     }

    //     return check(root -> left, minVal, root -> val) && 
    //             check(root -> right, root -> val, maxVal);
    // }
    int maxSumBST(TreeNode* root) {
        // if (!root) return 0;

        // int sum = 0;
        // if (check(root, INT_MIN, INT_MAX)) {
        //     sum = max(sum, dfs(root));
        // }

        // sum = max(sum, maxSumBST(root -> left));
        // sum = max(sum, maxSumBST(root -> right));

        int ans = 0;
        dfs(root, ans);
        return ans;
    }
 };
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int res = INT_MIN;
    int PathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftpart = max(PathSum(root->left), 0);
        int rightpart = max(PathSum(root->right), 0);

        int subtreesum = root->val + leftpart + rightpart;
        res = max(res, subtreesum);

        return root->val + max(leftpart, rightpart);
    }
    int maxPathSum(TreeNode* root) {
        PathSum(root);
        return res;
    }
};
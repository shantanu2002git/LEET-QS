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
    int s = 0;
    int call(TreeNode* root, int d) {
        if (root == NULL) {
            return s;
        }
        if (root->left == NULL && root->right == NULL && d == 1) {
            s = s + root->val;
        }
        call(root->left, 1);
        call(root->right, 0);

        return s;
    }
    int sumOfLeftLeaves(TreeNode* root) { call(root, -1);  return s;}
};
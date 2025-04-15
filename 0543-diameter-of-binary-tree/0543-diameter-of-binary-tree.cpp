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
    int call(TreeNode* nd) {
        if (nd == NULL) {
            return 0;
        }
        return max(call(nd->left), call(nd->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int left = call(root->left);
        int right = call(root->right);

        return (left + right);
    }
};
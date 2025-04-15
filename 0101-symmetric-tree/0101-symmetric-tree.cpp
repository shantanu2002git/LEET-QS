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
    bool call(TreeNode* left, TreeNode* right) {
        if(!right && !left){
            return true;
        }
        if (!right || !left) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }

        return (call(left->left, right->right) && call(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) { return call(root, root); }
};
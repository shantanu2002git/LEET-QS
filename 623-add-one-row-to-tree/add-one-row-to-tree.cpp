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
    TreeNode *lef, *rig, *main;
    void call(TreeNode* root, int d, int c, int vl) {
        if (root == NULL) {
            return;
        }
        if (d == c) {

            TreeNode* lefnd = new TreeNode(vl);
            TreeNode* raind = new TreeNode(vl);

            lefnd->left = root->left;
            raind->right = root->right;

            root->left = lefnd;
            root->right = raind;
            return;
        }
        call(root->left, d, c + 1, vl);
        call(root->right, d, c + 1, vl);
    }
    TreeNode* addOneRow(TreeNode* root, int vl, int depth) {
        if (depth == 1) {
            TreeNode* nd = new TreeNode(vl);
            nd->left = root;
            return nd;
        }
        call(root, depth - 1, 1, vl);
        return root;
    }
};
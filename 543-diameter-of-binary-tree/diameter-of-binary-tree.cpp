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
    int call(TreeNode* root, int& l) {
        if (root == NULL) {
            return 0;
        }
        int lef = call(root->left, l);
        int rig = call(root->right, l);
        l = max(l,lef+rig);
        return max(lef, rig)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int c = 0;
        call(root, c);
        return c;
    }
};
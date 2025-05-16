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
    int cnt = 0, res = 0;
    void call(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }

        call(root->left, k);
        cnt++;
        if (cnt == k) {
            res = root->val;
            return;
        }
        call(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        call(root, k);
        return res;
    }
};
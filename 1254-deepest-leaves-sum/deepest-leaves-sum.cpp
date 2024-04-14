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
    int sum = 0;
    void res(TreeNode* root, int l) {
        if (root == NULL) {
            return ;
        }

        if (l == 0) {
            sum = sum + root->val;
        }
        res(root->left, l - 1);
        res(root->right, l - 1);
       
    }
    int call_deep(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(call_deep(root->left), call_deep(root->right)) + 1;
    }
    int deepestLeavesSum(TreeNode* root) {
        int hi = call_deep(root);
        res(root, hi - 1);
        return sum;
    }
};
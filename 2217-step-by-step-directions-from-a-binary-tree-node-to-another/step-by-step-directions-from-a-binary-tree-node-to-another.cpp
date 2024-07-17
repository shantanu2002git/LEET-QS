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
    TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        if (root == NULL || root->val == n1->val || root->val == n2->val) {
            return root;
        }

        TreeNode* left = LCA(root->left, n1, n2);
        TreeNode* right = LCA(root->right, n1, n2);

        if (left == NULL) {
            return right;
        }

        if (right == NULL) {
            return left;
        }

        return root;
    }

    bool path(TreeNode* nd, int st, string& pp) {
        if (nd == NULL) {
            return false;
        }

        if (nd->val == st) {
            return true;
        }

        pp.push_back('L');
        if (path(nd->left, st, pp)) {
            return true;
        }
        pp.pop_back();

        pp.push_back('R');
        if (path(nd->right, st, pp)) {
            return true;
        }
        pp.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* nd = LCA(root, new TreeNode(startValue), new TreeNode(destValue));
        string st = "", en = "";
        path(nd, startValue, st);
        path(nd, destValue, en);

        for (char &c : st) {
            c = 'U';
        }

        return st + en;
    }
};

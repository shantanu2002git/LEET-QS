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
public://129. Sum Root to Leaf Numbers
    string res = ""; // res="zzzzzzz";
    void call(TreeNode* root, string s) {
        if (root == NULL) {
            return;
        }
        s = s + char('a' + root->val);
        if (root->left == NULL && root->right == NULL) {
            reverse(s.begin(), s.end());
            if (res.empty() || s < res) {
                res = s;
            }
            // res = min(res, s);
        }
        call(root->left, s);
        call(root->right, s);
        // s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        call(root, s);
        return res;
    }
};
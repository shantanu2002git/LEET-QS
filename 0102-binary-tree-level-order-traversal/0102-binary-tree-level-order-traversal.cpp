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
    vector<vector<int>> res;
    vector<int> in;
   void call(TreeNode* root, int lev) {
        if (in.size() == lev) {
            res.push_back(in);
            in.clear();
            return;
        }

        in.push_back(root->val);
        call(root->left, lev + 1);
        call(root->right, lev + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int lev = 0;
         call(root, lev);
         return res;
    }
};
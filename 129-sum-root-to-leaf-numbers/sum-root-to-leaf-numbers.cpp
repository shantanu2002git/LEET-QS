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
    int res = 0;
    void call(TreeNode* root, string s) {
       if (root == nullptr) {
            return;
        }
        
        s += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res += stoi(s);
        }
      
        call(root->left, s);
        call(root->right, s);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
         call(root, s);
         return res;
    }
};
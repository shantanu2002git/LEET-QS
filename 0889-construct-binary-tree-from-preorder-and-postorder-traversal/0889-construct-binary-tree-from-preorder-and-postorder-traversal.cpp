/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* call(int prestart, int preend, int poststart, int postend, 
                   vector<int>& preorder, vector<int>& postorder) {
        if (prestart > preend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        if (prestart == preend) {
            return root;
        }

        int leftRootVal = preorder[prestart + 1];
        int j = poststart;
        while (j <= postend && postorder[j] != leftRootVal) {
            j++;
        }

        int leftSize = j - poststart + 1;

        root->left = call(prestart + 1, prestart + leftSize, poststart, j, preorder, postorder);
        root->right = call(prestart + leftSize + 1, preend, j + 1, postend, preorder, postorder);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return call(0, n - 1, 0, n - 1, preorder, postorder);
    }
};

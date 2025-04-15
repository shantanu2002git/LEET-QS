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
int call(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left = call(root->left);
        if (left == -1) return -1;  // left subtree not balanced

        int right = call(root->right);
        if (right == -1) return -1; // right subtree not balanced

    if(abs(left-right)>1){
        return -1;
    }

    return max(left, right)+1;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        return call(root)!=-1;
    }
};
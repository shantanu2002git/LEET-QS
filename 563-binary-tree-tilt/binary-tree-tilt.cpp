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
int till=0;
int call(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int lef=call(root->left);
    int rig=call(root->right);

    till+=abs(lef - rig);
    return (lef + rig + root->val);
     
}
    int findTilt(TreeNode* root) {
        call(root);
        return till;
    }
};
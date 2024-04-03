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
bool call(TreeNode* root, TreeNode* _min , TreeNode* _max ){
    if(root==NULL){
        return 1;
    }
    if(_min && root->val<=_min->val || _max && root->val>=_max->val){
        return 0;
    }

    return call(root->left,_min,root) && call(root->right, root, _max);
}
    bool isValidBST(TreeNode* root) {
       return call(root, NULL, NULL); 
    }
};
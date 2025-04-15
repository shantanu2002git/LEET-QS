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
bool ans=1;
int cal(TreeNode* root){
    if(root==NULL) return 0;
    if(ans==0) return 0;

    int lefhi=cal(root->left);
    int righi=cal(root->right);
   if(abs(lefhi-righi)>1){
    ans=0;
     }
    return max(lefhi,righi)+1;
}
    bool isBalanced(TreeNode* root) {
      
      cal(root);
        return  ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
  TreeNode*  cal1(TreeNode* root, TreeNode* p, TreeNode* q){
      if(root==NULL){
          return NULL;
      }
      int vl=root->val;
      if(vl<p->val && vl<q->val){
        return  cal1(root->right,p,q);
      }
      if(vl>p->val && vl>q->val){
        return  cal1(root->left,p,q);
      }
      return root;
  }


  TreeNode*  cal2(TreeNode* root, TreeNode* p, TreeNode* q){
    while (root)
    {
        if (root->val > p->val && root->val > q->val)
            root = root->left;
        else if (root->val < q->val && root->val < p->val)
            root = root->right;
        else
            return root;
    }
    return NULL;/* O(height)  S.C O(1)*/
  }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return cal1(root,p,q);
    }
};
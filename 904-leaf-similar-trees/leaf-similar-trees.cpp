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
void call(TreeNode* root, vector<int>&as){
    if(root==NULL){
        return; 
    }
    call(root->left, as);
    if(root->left==NULL && root->right==NULL){
    as.push_back(root->val);
    }
    call(root->right,as);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>as1,as2,as;
        call(root1,as1);
       
        call(root2,as2);
        if(as1.size()!=as2.size()){
            return 0;
        }
        for(int i=0; i<as1.size(); i++){
            if(as1[i]!=as2[i]){
                return false;
            }
        }
        return true;
    }
};
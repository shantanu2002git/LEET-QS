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
map<int,int>mp;
int palic=0;
void call(TreeNode* root){
    if(root==NULL){
        return;
    }
    mp[root->val]++;
    if(root->left==NULL && root->right==NULL){
        int odd=0;
        for(auto it : mp){
            if(it.second & 1){
                odd++;
            }
        }
        if(odd<=1){
            palic++;
        }
    }

    call(root->left);
    call(root->right);
    mp[root->val]--;

}

    int pseudoPalindromicPaths (TreeNode* root) {
        call(root);
        return palic;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* fnt;
        while(!q.empty()){
            int n=q.size();
            vector<int>in;
            for(int i=0; i<n; i++){
               fnt=q.front();
                q.pop();
                in.push_back(fnt->val);
                if(fnt->left) q.push(fnt->left);
                if(fnt->right) q.push(fnt->right);

            }
            res.push_back(in);
        }
        return res;
    }
};
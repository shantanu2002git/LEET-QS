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
        queue<TreeNode*>q;
        vector<vector<int>>res;
        q.push(root);
        while(!q.empty()){
            vector<int>in;
            int n=q.size();
            for(int i=0; i<n; i++){
                auto it =q.front(); q.pop();
                in.push_back(it->val);
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            res.push_back(in);
        }
        return res;

    }
};
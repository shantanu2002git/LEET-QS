/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> in;
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();
                in.push_back(it->val);

                if (it->left) {
                    q.push(it->left);
                }
                if (it->right) {
                    q.push(it->right);
                }
            }
            
            if (level % 2 != 0) {
                reverse(in.begin(), in.end());
            }
            level++;
            res.push_back(in);
        }
        return res;
    }
};
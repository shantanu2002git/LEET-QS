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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        map<int, int> mp;
        int lv = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();
                mp[lv] = it->val;
                  if (it->left) { q.push(it->left); }
                if (it->right) {
                    q.push(it->right);
                }
            }
            lv++;
        }

        for (auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};
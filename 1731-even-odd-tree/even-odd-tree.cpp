#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr)
            return true;

        int ll = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> ll_val(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (ll % 2 == 0) { // even ll,  strictly increasing
                   if(node->val%2==0){
                       return 0;
                   }
                    if (i > 0 && ll_val[i - 1] >= node->val )
                        return false;
                } else { // odd ll, strictly decreasing
                if(node->val%2!=0){
                       return 0;
                   }
                    if (i > 0 && ll_val[i - 1] <= node->val)
                        return false;
                }

                ll_val[i] = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ll++;
        }

        return true;
    }
};

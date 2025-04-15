class Solution {
public:
    bool call(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;           // both are null → same
        if (!p || !q) return false;          // one is null → not same
        if (p->val != q->val) return false;  // different values

        // check left and right subtrees
        return call(p->left, q->left) && call(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return call(p, q);
    }
};

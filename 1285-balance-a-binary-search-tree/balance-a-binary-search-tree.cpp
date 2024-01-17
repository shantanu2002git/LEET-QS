class Solution {
public:
    void call_val(TreeNode* root, vector<int>& val) {
        if (root == nullptr) {
            return;
        }
        call_val(root->left, val);
        val.push_back(root->val);
        call_val(root->right, val);
    }

    TreeNode* Tree(vector<int>& arr, int st, int en) {
       if(st>en){
           return NULL;
       }
       int md=(st+en)/2;
       TreeNode* nod=new TreeNode(arr[md]);
       nod->left=Tree(arr,st,md-1);
       nod->right=Tree(arr,md+1,en);

       return nod;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> val;
        call_val(root, val);
        int n = val.size();
        return Tree(val, 0, n - 1);
    }
};

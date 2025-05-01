/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "NULL";
        }
        return to_string(root->val)+"*"+serialize(root->left)+"*"+serialize(root->right);

    }

TreeNode* decode(queue<string>&q){
    string is=q.front();
    q.pop();
    if(is=="NULL"){
        return NULL;
    }
    TreeNode* root=new TreeNode(stoi(is));
    root->left=decode(q);
    root->right=decode(q);

    return root;
}
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        string si;
        for(int i=0;i<data.size(); i++){
            if(data[i]=='*'){
                q.push(si);
                si="";
                continue;
            }
            si+=data[i];
        }
        if(si.size()!=0){
            q.push(si);
        }
        return decode(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
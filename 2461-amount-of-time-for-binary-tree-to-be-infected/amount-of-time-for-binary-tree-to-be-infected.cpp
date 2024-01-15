class Solution {
  private:
  void tree_grap(TreeNode* root,  unordered_map<int,vector<int>> &grap){
    if(root->left){
      grap[root->val].push_back(root->left->val);
      grap[root->left->val].push_back(root->val);
      tree_grap(root->left,grap);
    }
    if(root->right){
      grap[root->val].push_back(root->right->val);
      grap[root->right->val].push_back(root->val);
      tree_grap(root->right,grap);
    }
  }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>grap;
        unordered_map<int,bool>vist;
        queue<pair<int,int>>q;

        tree_grap(root,grap);
        int mx=-1e9;
        q.push({start,0});
        while(!q.empty()){
          auto fnt=q.front();
          q.pop();
          int nd=fnt.first,dis=fnt.second;
          mx=max(mx,dis);
          vist[nd]=1;
          for(auto it : grap[nd]){
            if(!vist[it]){
              q.push({it,dis+1});
            }
          }
        }
        return mx;
    }
};
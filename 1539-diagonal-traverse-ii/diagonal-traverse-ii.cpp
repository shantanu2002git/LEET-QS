class Solution {
public:
   vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size();
        queue<pair<int, int>> q;
        vector<int> res;
        q.push({0, 0});
        while (!q.empty())
        {
            auto fn = q.front();
            q.pop();
            int rw = fn.first;
            int cl = fn.second;
            res.push_back(mat[rw][cl]);
            if (cl == 0 && rw + 1 < n)
            {
                q.push({rw + 1, cl});
            }
           if (cl + 1 < mat[rw].size())
            {
                q.push({rw, cl + 1});
            }
        }
        return res;
    }
};
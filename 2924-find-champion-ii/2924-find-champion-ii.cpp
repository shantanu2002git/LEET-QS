class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n];
        vector<int> ind(n, 0);
        int fnd = -1;
        for (auto it : edges)
        {
            adj[it[1]].push_back(it[0]);
            ind[it[1]]++;
        }
        queue<int> q;
        for (int i=0; i<n; i++)
        {
           
            if (ind[i] == 0)
            {
              
                q.push(i);
                fnd = i;
                // break;
            }
        }

        while (!q.empty())
        {
           
            int tp = q.front();
            q.pop();
            for (auto it : adj[tp])
            {
                
                ind[it]--;
                if (ind[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        // cout<<fnd;
        return (q.size() == 0) ? fnd : -1;
    }
};
class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        vector<vector<int>> res;

        // Step 1: Create adjacency list and track in-degrees and out-degrees
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inDegree, outDegree;

        for (auto &pair : pairs)
        {
            int u = pair[0], v = pair[1];
            adj[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Step 2: Find the start node
        int startNode = pairs[0][0]; // Default start node
        for (auto &[node, out] : outDegree)
        {
            if (out > inDegree[node])
            {
                startNode = node;
                break;
            }
        }

        // Step 3: Perform Eulerian Path (Hierholzer's Algorithm)
        stack<int> st;
        st.push(startNode);

        while (!st.empty())
        {
            int u = st.top();

            if (!adj[u].empty())
            {
                int v = adj[u].back();
                adj[u].pop_back(); // Remove edge u -> v
                st.push(v);
            }
            else
            {
                res.push_back({u});
                st.pop();
            }
        }

        // Step 4: Convert single-node path into pair representation
        reverse(res.begin(), res.end());
        vector<vector<int>> finalRes;
        for (int i = 1; i < res.size(); i++)
        {
            finalRes.push_back({res[i - 1][0], res[i][0]});
        }

        return finalRes;
    }
};

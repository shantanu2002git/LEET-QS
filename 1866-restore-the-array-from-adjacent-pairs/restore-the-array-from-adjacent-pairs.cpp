
class Solution
{
public:
    // time/space: O(n)/O(n)
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        int n = adjacentPairs.size() + 1;
        // build the graph
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for (auto &pair : adjacentPairs)
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
            indegree[pair[0]]++;
            indegree[pair[1]]++;
        }

        // find the start/end node
        int start;
        queue<int> q;
        for (auto it : indegree)
        {
            if (it.second == 1)
            {
                start = it.first;
                q.push(start);
                break;
            }
        }

        // traverse the graph
        int curr = start, prev = INT_MIN;
        vector<int> nums;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int fnt = q.front();
                q.pop();
                nums.push_back(fnt);
                for (auto it : graph[fnt])
                {
                    if (it != prev)
                    {
                        prev = fnt;
                        q.push(it);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};
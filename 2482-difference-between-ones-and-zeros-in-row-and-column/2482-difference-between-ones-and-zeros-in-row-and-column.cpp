class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        map<int, pair<int, int>> mprw;
        vector<int> columon(m, 0);
        vector<int> columze(m, 0);
        int clon = 0, clze = 0, cl = 0;
        for (int i = 0; i < n; i++)
        {
            int rwon = 0, rwze = 0;

            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    columze[j]++;
                    rwze++;
                }
                else
                {
                    rwon++;
                    columon[j]++;
                }
            }
            mprw.insert({i, {rwon, rwze}});
        }

        for (auto i : mprw)
        {
            cout << i.first << " one : " << i.second.first << " zero : " << i.second.second << endl;
        }

        cout << "--------------------" << endl;

        for (int i = 0; i < m; i++)
        {
            cout << i << " one : " << columon[i] << " zero : " << columze[i] << endl;
        }

        for (int i = 0; i < n; i++)
        {
            auto it = mprw.at(i);
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = (it.first + columon[j]) - (it.second + columze[j]);
            }
        }
        // auto it = mprw.at(1);
        // cout << it.first;
        return grid;
    }
};

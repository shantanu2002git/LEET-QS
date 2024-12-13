class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
       
        long long res = 0;
        int n = nums.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
           
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end(), [&](pair<int, int> p1, pair<int, int> p2)
             { return (p1.first == p2.first) ? p1.second < p2.second : p1.first < p2.first; });

        vector<int> marking(n + 1, 0);
        for (auto it : vp)
        {
            int idx = it.second;
            if (marking[idx] == 0)
            {
                int pv = max(idx - 1, 0), nx = min(idx + 1, n - 1);
                marking[idx] = 1;
                marking[pv] = 1;
                marking[nx] = 1;

                res = res + it.first;
            }

            cout << it.first << " " << it.second << endl;
        }

        return res;
    }
};

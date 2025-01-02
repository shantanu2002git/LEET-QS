
class Solution
{
public:
    bool valid(string s)
    {
        char vl[5] = {'a', 'e', 'i', 'o', 'u'};
        bool fsc = 0, lsc = 0;
        for (int i = 0; i < (sizeof(vl) / sizeof(char)); i++)
        {
            if (s[0] == vl[i])
            {
                fsc = 1;
            }
            if (s[s.size() - 1] == vl[i])
            {
                lsc = 1;
            }
        }
        return (fsc && lsc);
    }
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        prefix[0] = valid(words[0]);
        for (int i = 1; i < n; i++)
        {
            string it = words[i];
            if (valid(it))
            {
                prefix[i] = prefix[i - 1] + 1;
            }
            else
            {
                prefix[i] = prefix[i - 1];
            }
        }

        for (auto it : prefix)
        {
            cout << it << " ";
        }
        cout<<endl;
        vector<int> res;
        for (auto it : queries)
        {
            if (it[0] == 0)
            {
                res.push_back(prefix[it[1]]);
            }
            else
            {
                res.push_back((prefix[it[1]]-prefix[it[0]-1]));
            }
        }
        return res;
    }
};

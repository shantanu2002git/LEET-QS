class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j && words[i].find(words[j]) != string::npos)
                {
                    res.push_back(words[j]);
                }
            }
        }
        // Remove duplicates
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};


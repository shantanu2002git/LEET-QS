class Solution {
public:
  int countPrefixSuffixPairs(vector<string> &words)
  {
    int n = words.size(), c = 0;
    for (int i = 0; i < n; i++)
    {
      int s = words[i].size();
      for (int j = i + 1; j < n; j++)
      {
        int t = words[j].size();
        if (words[j].substr(0, s) == words[i].substr(0, s) && words[j].substr(t - s, s) == words[j].substr(0, s))
        {
          c++;
        }
      }
    }
    return c;
  }
};
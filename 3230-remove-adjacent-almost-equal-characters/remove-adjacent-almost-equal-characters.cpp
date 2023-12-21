class Solution
{
public:
    int removeAlmostEqualCharacters(string s)
    {
        int n = s.size(), c = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == s[i] || (int)s[i - 1] + 1 == (int)s[i] || (int)s[i - 1] == (int)s[i]+1  )
            {
                c++;
                s[i] = '*';
                continue;
            }
        }
        return c;
    }
};
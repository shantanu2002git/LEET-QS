
class Solution
{
public:
    string makeFancyString(string s)
    {
        stack<pair<char, int>> q;
        int n = s.size(), c = 1;
        for (int i = 0; i < n; i++)
        {
            if (q.empty())
            {
                q.push({s[i], c});
            }
            else if (q.top().first == s[i])
            {
                if (q.top().second >= 2)
                {
                    cout << "hi";
                    continue;
                }
                c=c+1;
                q.push({s[i], c});
            }
            else
            {
                c = 1;
                q.push({s[i], c});
            }
        }

        string res = "";
        while (!q.empty())
        {
            cout<<q.top().first<<" "<<q.top().second<<endl;
            res = res + q.top().first;
            q.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = s[0] == '0';
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                left[i] = left[i - 1] + 1;
            }
            else
            {
                left[i] = left[i - 1];
            }
        }

        right[n - 1] = (s[n - 1] == '1');
        bool fl0=0, fl1=0;
        for (int i = n - 2; i >= 0; i--)
        {
            
            if (s[i] == '1')
            {
                right[i] = right[i + 1] + 1;
                fl1=1;
            }
            else
            {
                right[i] = right[i + 1];
            }
            if(fl1){
                fl0=1;
            }
        }
        /*
                for (auto it : left)
                {
                    cout << it << " ";
                }
                cout << endl;
                for (auto it : right)
                {
                    cout << it << " ";
                }
                */
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, (left[i] + right[i]));
        }
        return (left[n-1]==0  || fl0)? res-1 : res;
    }
};

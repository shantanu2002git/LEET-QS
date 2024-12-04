class Solution
{
public:
    bool canMakeSubsequence(string st1, string st2)
    {
        int n = st1.size(), m = st2.size();

        char s = 'a'; // 97
        // cout<<(char) 98;
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            if ((st1[i] == st2[l]) || (st2[l] - st1[i]) == 1)
            {
                l++;
            }else if(st1[i]=='z' && st2[l]=='a'){
                l++;
            }
        }
        cout << l;
        return l == m;
    }
};
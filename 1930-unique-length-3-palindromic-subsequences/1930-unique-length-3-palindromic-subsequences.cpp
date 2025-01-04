class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        // cout<<(int) 'a';//97

        int n = s.size();
        vector<int> count(27, 0);
        map<char, int> index;
        int res = 0,si3=0;

        for (int i = 0; i < n; i++)
        {
            int ci = s[i] - 97;
            if (count[ci] == 0)
            {
                index.insert({s[i], i});
            }
            count[ci]++;
        
            if (count[ci] >= 2)
            {
               
                int lens = (i - index[s[i]]) + 1;
                res = res + (abs(lens - count[ci]));

                cout<<s[i]<<" "<<lens<<" "<<abs(lens - count[ci])<<" "<<res<<endl;
                index.erase(s[i]);
                index.insert({s[i], i});
                count[ci]--;
            }
            // cout << ci << " ";
        }

        return res;
    }
};

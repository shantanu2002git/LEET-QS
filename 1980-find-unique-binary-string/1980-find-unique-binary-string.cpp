class Solution
{
public:
    set<string> st;

    string cal(int idx, char bin[2], int n, string s)
    {
        if (idx >= n)
        {
            if (!st.count(s))
            {
                return s;
            }
            return "";
        }

        string s1 = s + bin[0];
        string s2 = s + bin[1];

        string res = cal(idx + 1, bin, n, s1);
        if (!res.empty())
        {
            return res;
        }
        return cal(idx + 1, bin, n, s2);
    }





    string findDifferentBinaryString(vector<string> &nums)
    {
        for (auto it : nums)
        {
            st.insert(it);
        }
        int n = nums.size();
        char bin[2] = {'0', '1'};
        string s = "";
        return cal(0, bin, n, s);
    }
};
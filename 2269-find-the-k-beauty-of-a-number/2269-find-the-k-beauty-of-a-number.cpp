class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string st = to_string(num);
        int ki, c = 0;
        for (int i = 0; i < st.size() - k + 1; i++)
        {
            ki = stoi(st.substr(i, k));
            cout << ki << " ";
            if (ki == 0)
            {
                continue;
            }
            if (num % ki == 0)
            {
                cout << ki << endl;
                c++;
            }
        }
        return c;
    }
};

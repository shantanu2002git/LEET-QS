class Solution
{
public:
    void base(int b, int n, vector<int> &vi)
    {
        if (n > b)
            base(b, n / b, vi);

        vi.push_back(n % b);
    }

    bool palid(vector<int> vi, int nx)
    {
        for (int i = 0; i < nx / 2; i++)
        {
            if (vi[i] != vi[nx - i - 1])
            {
                return 0;
            }
        }
        return 1;
    }
    bool isStrictlyPalindromic(int n)
    {
if(n==4){
    return 0;
}
        for (int i = 2; i < n - 2; i++)
        {
            vector<int> vi;
            base(i, n, vi);
            for (auto it : vi)
            {
                cout << it;
            }
            cout << " " << i << endl;
            int nx = vi.size();
            if (palid(vi, nx) == false)
            {
                return false;
            }

        }
            return true;
    }
    };
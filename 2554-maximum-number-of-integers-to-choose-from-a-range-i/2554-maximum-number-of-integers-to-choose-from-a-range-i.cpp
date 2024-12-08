class Solution
{
public:
    int maxCount(vector<int> &bann, int n, int target)
    {
        set<int> st;
        for (int i : bann)
        {
            st.insert(i);
        }
        vector<int> nwarr;
        for (int i = 1; i <= n; i++)
        {
            if (st.count(i) == 0)
            {
                nwarr.push_back(i);
            }
        }
        int sum = 0, res = 0;
        for (auto it : nwarr)
        {
            if (target - it >= 0)
            {
                res++;
                cout << it << " ";
                target = target - it;
            }
        }
        /*
        int m = bann.size();
        for (int i = 1; i <= n; i++)
        {
            int fn = i;
            int l = 0, r = m, flg = 0;
            while (l < r)
            {
                int md = (l + r) / 2;
                if (bann[md] == fn)
                {
                    cout<<fn<<"---";
                    flg = 1;
                    //break;
                }
                if (bann[md] > fn)
                {
                    r = md - 1;
                }
                else if(bann[md] < fn)
                {
                    l = md + 1;
                }
            }
            if (!flg)
            {
                if (target - fn >= 0)
                {
                    res++;
                  //  cout << fn << " ";
                    target = target - fn;
                }
            }
        }*/
        return res;
    }
};

/*
if the question ask "maximum number of integers you can choose to get Target Sum..."
*/
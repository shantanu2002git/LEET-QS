class Solution
{
public:
    vector<int> selfDividingNumbers(int lf, int ri)
    {
        vector<int> res;
        map<char, int> mp{
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9},
        };
        for (int i = lf; i <= ri; i++)
        {
            string si = to_string(i);
            bool flag = true;
            if (si.find('0') != string::npos)
            {
                cout<<"0000";
                continue;
            }
            else
            {
                for (char l = '1'; l <= '9'; l++)
                {
                    if (si.find(l)!= string::npos)
                    {
                        if(i%mp[l]!=0){
                            cout<<"lop";
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(flag){
                res.push_back(i);
            }
        }
        return res;
    }
};

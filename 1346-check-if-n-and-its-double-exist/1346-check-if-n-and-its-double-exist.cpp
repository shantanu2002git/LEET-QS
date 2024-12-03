
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, int> mp;

        for (int num : arr)
        {
            if (mp.find(num * 2) != mp.end())
            {
                return true;
            }
           if (num % 2 == 0 && mp.find(num / 2) != mp.end())
            {
                return true;
            }

            mp[num]++;
        }

        return false;
    }
};

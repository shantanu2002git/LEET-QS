class Solution
{
public:
    int maxSubarrayLength(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0, j = 0, mx = 1;
        map<int, int> mp;
        while (i < n)
        {
            mp[arr[i]]++;
            while (mp[arr[i]] > k)
            {
                    mp[arr[j]]--;
                j++;
            }
                mx = max(i - j+1, mx);
            i++;
        }
        return mx;
    }
};
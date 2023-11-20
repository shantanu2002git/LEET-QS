class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int th)
    {
        int n = arr.size();
        int i = 0, j = 0, s = 0, count = 0;
        while (i < n)
        {
            s = s + arr[i];
            if (i - j == k - 1)
            {
                if (s / k >= th)
                    count++;
                cout<<s<<endl;
                s = s - arr[j];
                j++;
            }
            i++;
        }
        return count;
    }
};
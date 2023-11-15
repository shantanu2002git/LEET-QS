class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size(), mx = -1;
        arr[0]=1;
        for (int i = 1; i < n; i++)
        {
            if (abs(arr[i] - arr[i - 1]) <= 1)
            {
                //mx = max(mx, max(arr[i], arr[i - 1]));
                continue;
            }
            arr[i] = arr[i - 1] + 1;
           // mx = max(mx, max(arr[i], arr[i - 1]));
        }
        for(auto it : arr){
            cout<<it<<" ";
        }
        mx=*max_element(arr.begin(),arr.end());
        return mx;
    }
    };
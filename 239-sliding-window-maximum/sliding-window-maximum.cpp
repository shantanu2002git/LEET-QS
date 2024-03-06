class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> res;
        multiset<int> ms;

        int i = 0, j = 0,n=arr.size();
        while (i < n) {
            ms.insert(arr[i]);
            if (ms.size() == k) {

                int val = *(--ms.end());
                res.push_back(val);
                ms.erase(ms.find(arr[j]));

                j++;
            }
            i++;
        }
        return res;
    }
};
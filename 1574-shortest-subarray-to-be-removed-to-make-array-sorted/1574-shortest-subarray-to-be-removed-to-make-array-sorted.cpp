class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // Find the leftmost sorted prefix
        int st = 0;
        while (st + 1 < n && arr[st] <= arr[st + 1]) {
            st++;
        }

        // If the entire array is already sorted
        if (st == n - 1) {
            return 0;
        }

        // Find the rightmost sorted suffix
        int en = n - 1;
        while (en > 0 && arr[en - 1] <= arr[en]) {
            en--;
        }

        // Calculate the result by considering three cases:
        // 1. Remove the entire middle part.
        int result = min(n - st - 1, en);

        // 2. Try merging the prefix and suffix
        int i = 0, j = en;
        while (i <= st && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};

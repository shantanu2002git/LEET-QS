class Solution {
public:
    long long dividePlayers(vector<int>& sl) {
        sort(sl.begin(), sl.end());
        int n = sl.size();
        long long targetSum = sl[0] + sl[n - 1];
        long long res = (long long)sl[0] * sl[n - 1];

        int i = 1, j = n - 2;

        while (i < j) {
            if ((sl[i] + sl[j]) == targetSum) {
                res += (long long)sl[i] * sl[j];

            } else {
                return -1;
            }
            i++;
            j--;
        }
        return res;
    }
};

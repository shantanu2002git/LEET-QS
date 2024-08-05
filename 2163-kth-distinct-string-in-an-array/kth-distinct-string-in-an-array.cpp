class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size(), c = 0;
        for (int i = 0; i < n; i++) {
            int fl = 1;
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j] && i != j) {
                    fl = 0;
                    break;
                }
            }
            if (fl == 1) {
                c++;
                if (c == k) {
                    return arr[i];
                }
            }
        }
        return "";
    }
};
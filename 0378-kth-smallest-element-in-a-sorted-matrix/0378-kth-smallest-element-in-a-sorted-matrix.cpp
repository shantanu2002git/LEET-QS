class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0, row = n - 1, col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1); // all elements above are ≤ mid
                col++;
            } else {
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = countLessEqual(matrix, mid, n);
            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

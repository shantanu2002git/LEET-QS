#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        int i = 0, j = n - 1, md;
        while (i <= j) {
            md = i + (j - i) / 2;
            if (arr[md] == x) {
                i = md;
                break;
            } else if (arr[md] < x) {
                i = md + 1;
            } else {
                j = md - 1;
            }
        }

        int left = i - 1, right = i;
        while (k > 0) {
            if (left >= 0 && (right >= n || abs(arr[left] - x) <= abs(arr[right] - x))) {
                res.push_back(arr[left]);
                left--;
            } else {
                res.push_back(arr[right]);
                right++;
            }
            k--;
        }

        sort(res.begin(), res.end());
        return res;
    }
};

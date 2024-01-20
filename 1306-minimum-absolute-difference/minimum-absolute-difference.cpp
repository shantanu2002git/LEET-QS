#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::vector<std::vector<int>> res;
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        int mx = 1e9;
        
        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            
            if (diff == mx) {
                res.push_back({arr[i - 1], arr[i]});
            } else if (diff < mx) {
                mx = diff;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return res;
    }
};

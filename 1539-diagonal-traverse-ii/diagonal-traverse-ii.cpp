#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> groups;

        // Loop starting from the first row
        for (int row = 0; row < nums.size(); row++) {
            for (int col = 0; col < nums[row].size(); col++) {
                int diagonal = row + col;
                groups[diagonal].push_back(nums[row][col]);
            }
        }

        vector<int> ans;
        int curr = 0;

        while (groups.find(curr) != groups.end()) {
            vector<int> in = groups[curr];
            reverse(in.begin(), in.end());
            for (int num : in) {
                ans.push_back(num);
            }
            curr++;
        }
        return ans;
    }
};

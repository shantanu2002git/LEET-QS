#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;

        for (int house : houses) {
            int minDist = INT_MAX;

            for (int heater : heaters) {
                minDist = min(minDist, abs(house - heater)); // Find closest heater
            }

            res = max(res, minDist); // Max radius required
        }

        return res;
    }
};

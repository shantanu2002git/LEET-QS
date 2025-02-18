class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lw = 1, hi = 1e7, n = dist.size(); // Increase high to cover large test cases
        int res = -1; // Default case if no valid speed is found

        while (lw <= hi) {  
            int md = (lw + hi) / 2;  // Use int for binary search
            double spd = 0;  // Use double for time calculation

            for (int i = 0; i < n; i++) {
                if (i == n - 1) {
                    spd += (double) dist[i] / md;  // Floating-point division
                } else {
                    spd += ceil((double) dist[i] / md);  // Round up for integer parts
                }
            }

            if (spd > hour) { 
                lw = md + 1;  // Speed too slow, increase speed
            } else {  
                res = md;  // Store the valid speed
                hi = md - 1;  // Try to find a smaller valid speed
            }
        }
        return res;
    }
};

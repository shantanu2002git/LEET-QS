#define ll long long

class Solution {
public:
    long long minimumTime(vector<int>& time, int tp) {
        ll mx = *max_element(time.begin(), time.end());
        ll lw = 1, hai = mx, res = mx;

        while (lw <= hai) {
            ll md = (lw + hai) / 2;
            ll btime = 0;

            for (auto it : time) {
                btime += md / it;  
            }

            if (btime >= tp) {
                res = md;  // Store the valid minimum time
                hai = md - 1;  
            } else {
                lw = md + 1;  
            }
        }
        return res;
    }
};

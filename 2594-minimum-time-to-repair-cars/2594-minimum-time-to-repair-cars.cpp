class Solution {
public:
    long long repairCars(vector<int>& ranks, int car) {
        long long mi = 1;
        long long mxmi = (long long)*min_element(ranks.begin(), ranks.end()) * (long long)car * (long long)car;
        long long res = -1;

        while (mi <= mxmi) {
            long long md = mi + (mxmi - mi) / 2;
            long long cars = 0;
            
            for (auto it : ranks) {
                cars += (long long) sqrt(md / it);
            }

            if (cars >= car) { 
                res = md;
                mxmi = md - 1; 
            } else {
                mi = md + 1; 
            }
        }

        return res;
    }
};

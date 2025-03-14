#define ll long long

class Solution {
public:
    int maximumCandies(vector<int>& cand, long long k) {
        ll sum = accumulate(cand.begin(), cand.end(), 0LL); 
        ll lw = 1, hi = sum / k, res = 0; // Upper bound should be total candies / children

        while (lw <= hi) {
            ll md = lw + (hi - lw) / 2; 

            ll count = 0;
            for (auto it : cand) {
                count += it / md; // Number of children that can get 'md' candies each
            }

            if (count >= k) { // If we can distribute to at least 'k' children
                res = md; // Store the valid answer
                lw = md + 1; // Try to maximize
            } else {
                hi = md - 1; // Reduce search space
            }
        }
        return res;
    }
};

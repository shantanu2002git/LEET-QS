class Solution {
public:

/*
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 
https://leetcode.com/problems/minimum-time-to-repair-cars

*/
    int minEatingSpeed(vector<int>& piles, int h) {
        int mxk = *max_element(piles.begin(), piles.end());
        int mink = 1, res = mxk;

        while (mink <= mxk) {
            int md = (mink + mxk) / 2;
            int sumh = 0;

            for (int i = 0; i < piles.size(); i++) {
                sumh += ceil((double)piles[i] / md);
            }

            if (sumh > h) { 
              
                mink = md + 1;
            } else {
                // Speed is valid, try smaller values
                res = md;
                mxk = md - 1;
            }
        }

        return res;
    }
};

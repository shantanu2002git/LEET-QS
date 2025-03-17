class Solution {
public://https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
    long long cal(vector<int>& arr, int div) {
        long long si = 0;
        for(int i = 0; i < arr.size(); i++) {
            si = si + ceil((double)arr[i] / div);
        }
        return si;
    }
    
    int minEatingSpeed(vector<int>& nums, int h) {
        int st = 1, en = *max_element(nums.begin(), nums.end());
        while (st <= en) {
            int mid = (st + en) / 2;
            long long vl = cal(nums, mid);
            if (vl > h) {
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }
        return st;
    }
};

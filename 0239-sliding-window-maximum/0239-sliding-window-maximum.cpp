class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        vector<int> res;
        multiset<int> mst;
        while (i < n) {
            mst.insert(nums[i]);
            if (mst.size() == k) {

                auto it = mst.rbegin(); 
                // reverse sort format, big element infront()
                res.push_back(*it);
                mst.erase(mst.find(nums[j]));
                /*
                mst.erase(nums[j]);
This removes all occurrences of nums[j] from multiset.


mst.erase(mst.find(nums[j]));
Only removes one instance of nums[j], leaving other occurrences untouched.
                */
                j++;
            }

            i++;
        }
        return res;
    }
};
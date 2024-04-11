class Solution {
public:
    int count(vector<int>& a, int k) {
        int s = 0, e = a.size() - 1;
        int ans = a.size();
        while (s <= e) {
            int mid = (e + s) / 2;
            if (a[mid] > k)
                ans = mid;
            if (a[mid] > k)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return ans;
    }

    vector<int> resultArray(vector<int>& nums) {
        vector<int> a, b, c, d;
        int n = nums.size();
        a.push_back(nums[0]);
        b.push_back(nums[1]);

        c.push_back(nums[0]);
        d.push_back(nums[1]);
        for (int i = 2; i < n; i++) {
            int x = a.size() - count(a, nums[i]);
            int y = b.size() - count(b, nums[i]);
            if (x > y) {
                a.insert(a.end() - x, nums[i]);
                c.push_back(nums[i]);
            } else if (x < y) {
                b.insert(b.end() - y, nums[i]);
                d.push_back(nums[i]);
            } else {
                if (a.size() > b.size()) {
                    b.insert(b.end() - y, nums[i]);
                    d.push_back(nums[i]);
                } else {
                    a.insert(a.end() - x, nums[i]);
                    c.push_back(nums[i]);
                }
            }
        }
        c.insert(c.end(), d.begin(), d.end());
        return c;
    }
};
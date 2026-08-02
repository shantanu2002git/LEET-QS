class Solution {
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, long long val) {
            for (++idx; idx <= n; idx += idx & -idx)
                bit[idx] += val;
        }

        long long sum(int idx) {
            long long res = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                res += bit[idx];
            return res;
        }

        long long rangeSum(int l, int r) {
            if (l > r) return 0;
            return sum(r) - (l ? sum(l - 1) : 0);
        }
    };

    long long countPairs(vector<long long>& vals) {
        vector<long long> comp = vals;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        Fenwick ft(comp.size());

        long long res = 0;
        long long seen = 0;

        for (long long x : vals) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin();

            long long lessThan = ft.sum(idx - 1);
            res += seen - lessThan; // count previous >= current

            ft.add(idx, 1);
            seen++;
        }

        return res;
    }

public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<int> norvelith = nums; // required by statement

        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        vector<int> oddPref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];

            if (nums[i] & 1) {
                pref[i + 1] -= a;
                oddPref[i + 1] = oddPref[i] + 1;
            } else {
                pref[i + 1] += b;
                oddPref[i + 1] = oddPref[i];
            }
        }

        long long total = countPairs(pref);

        unordered_map<int, vector<long long>> groups;
        for (int i = 0; i <= n; i++) {
            groups[oddPref[i]].push_back(pref[i]);
        }

        long long invalid = 0;
        for (auto& [_, vec] : groups) {
            invalid += countPairs(vec);
        }

        return total - invalid;
    }
};
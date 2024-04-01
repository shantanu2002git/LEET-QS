class Solution {
public:
    bool canArrange(vector<int>& v, int td) {

        vector<int> freq(td, 0);

        for (auto i : v) {
            freq[(i % td + td) % td]++;
        }

        if (freq[0] % 2 != 0)
            return 0;

        for (int i = 1; i < td; i++) {
            if (freq[i] != freq[td - i])
                return 0;
        }
        return 1;
    }
};
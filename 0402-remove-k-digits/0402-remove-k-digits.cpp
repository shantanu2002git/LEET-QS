class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n) return "0";  // If k >= n, remove all digits

        string res;  

        for (char c : num) {
            while (!res.empty() && res.back() > c && k > 0) {
                res.pop_back();  // Remove the last digit to maintain smallest order
                k--;
            }
            res.push_back(c);
        }

        // Remove remaining `k` digits from the end if needed
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};

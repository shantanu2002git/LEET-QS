class Solution {
public:
    set<int> result; // use set to avoid duplicates

    void call(vector<int>& digits, vector<bool>& used, string s, int depth) {
        if (s.size() == 3) {
            if (s[0] != '0' && (s[2] - '0') % 2 == 0) {
                result.insert(stoi(s));
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            call(digits, used, s + to_string(digits[i]), depth + 1);
            used[i] = false;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);
        call(digits, used, "", 0);
        return vector<int>(result.begin(), result.end());
    }
};

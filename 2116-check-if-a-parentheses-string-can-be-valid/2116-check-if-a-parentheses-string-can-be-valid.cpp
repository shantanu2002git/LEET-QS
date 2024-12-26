class Solution {
public:
    bool canBeValid(string s, string locked) {
        int open = 0, clos = 0, canflip = 0, isblance = 0;
        int n = s.size();
        if (n % 2 != 0) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                canflip++;
            } else if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                clos++;
            }
            isblance = clos - open;
            if (canflip < isblance) {
                return false;
            }
        }
        open = 0, clos = 0, canflip = 0, isblance = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                canflip++;
            } else if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                clos++;
            }
            isblance = clos - open;
            if (canflip < isblance) {
                return false;
            }
        }
        return true;
    }
};
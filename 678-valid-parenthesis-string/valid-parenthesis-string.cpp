class Solution {
public://NOT ME_____________________
    bool checkValidString(string s) {
        int n = s.size();
        int minOpen = 0, maxOpen = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            } else if (s[i] == ')') {
                minOpen = max(0, minOpen - 1);
                maxOpen--;
                if (maxOpen < 0) {
                    return false;
                }
            } else {
                minOpen = max(0, minOpen - 1);
                maxOpen++;
            }
        }
        return minOpen == 0;
    }
};

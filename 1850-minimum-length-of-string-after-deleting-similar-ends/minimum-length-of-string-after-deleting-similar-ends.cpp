#include <string>
#include <algorithm>

class Solution {
public:
    int minimumLength(std::string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j && s[i] == s[j]) {
            char cr = s[i];
            while (i <= j && s[i] == cr)
                i++;
            while (i <= j && s[j] == cr)
                j--;
        }

        return max(0, j - i + 1);
    }
};

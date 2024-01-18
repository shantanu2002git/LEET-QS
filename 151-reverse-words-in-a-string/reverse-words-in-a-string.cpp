#include <iostream>
#include <algorithm>  // For std::reverse
#include <sstream>    // For std::istringstream
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Remove leading and trailing spaces
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        // Replace multiple spaces with a single space
        istringstream iss(s);
        
        string word, res;

        while (iss >> word) {
            if (!res.empty()) {
                res += ' ';
            }
            reverse(word.begin(), word.end());
            res += word;
        }
reverse(res.begin(), res.end());
        return res;
    }
};

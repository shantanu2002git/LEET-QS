#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }

      vector<pair<char, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](pair<char, int> a1, pair<char, int> a2) {
            return a1.second > a2.second;
        });

        string res = "";
        for (auto it : vec) {
            int n = it.second;
            char c = it.first;
            while (n--) {
                res += c;
            }
        }
        return res;
    }
};

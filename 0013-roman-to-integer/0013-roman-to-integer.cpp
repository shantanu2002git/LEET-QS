class Solution {
public:
    int romanToInt(string s) {
        map<char, int> sym{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                           {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size();
        int sum = sym[s.back()];
        for (int i = n - 2; i >= 0; i--) {
            if (sym[s[i + 1]] > sym[s[i]]) {
                sum = sum - sym[s[i]];
            }else{
                sum=sum+sym[s[i]];
            }
        }
        return sum;
    }
};
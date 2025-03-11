class Solution {
public:
    bool isallthree(vector<int>&fq) {
        return (fq[0] >= 1 && fq[1] >= 1 && fq[2] >=1);
    }
    int numberOfSubstrings(string s) {

        int n = s.size();
        int i = 0, j = 0;
        vector<int> fq(3, 0);
        int res = 0;

        while (i < n) {
            fq[s[i] - 'a']++;
            while (isallthree(fq)) {
                res = res + (n - i);

                fq[s[j] - 'a']--;
                j++;
            }
            i++;
        }
        return res;
    }
};
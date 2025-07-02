class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), res = 1;
        //  map<char,int>mps;
        for (int i = 1; i < n; i++) {
            if (word[i - 1] == word[i]) {
                res++;
            }
        }
        return res;
    }
};

/*

abbcccc
a=1
b=2
c=4

[ a1b2 c1, a1b2 c2, a1b2 c3, a1b2 c4
a1b1 c4, ] a1b1c1, a1b1c2 , a1b1c3 , a1b1b4



*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string call(int idx1, int idx2, int m, int n, string& s1, string& s2) {
        // Base Cases
        if (idx1 == m)
            return s2.substr(idx2);
        if (idx2 == n)
            return s1.substr(idx1); // If s2 is exhausted, return remaining s1

        if (s1[idx1] == s2[idx2]) {
            return s1[idx1] + call(idx1 + 1, idx2 + 1, m, n, s1, s2);
        }

        // If characters don't match, try both ways and take the shortest result
        string takeS1 = s1[idx1] + call(idx1 + 1, idx2, m, n, s1, s2);
        string takeS2 = s2[idx2] + call(idx1, idx2 + 1, m, n, s1, s2);

        return (takeS1.size() < takeS2.size()) ? takeS1 : takeS2;
    }

    string memocall(int idx1, int idx2, int n, int m, string& str1,
                    string& str2, vector<vector<string>>& dp) {
        if (idx1 == n)
            return str2.substr(idx2);
        if (idx2 == m)
            return str1.substr(idx1);

        if (dp[idx1][idx2] != "")
            return dp[idx1][idx2];

        if (str1[idx1] == str2[idx2]) {
            return dp[idx1][idx2] = str1[idx1] + memocall(idx1 + 1, idx2 + 1, n,
                                                          m, str1, str2, dp);
        }

        string takeStr1 =
            str1[idx1] + memocall(idx1 + 1, idx2, n, m, str1, str2, dp);
        string takeStr2 =
            str2[idx2] + memocall(idx1, idx2 + 1, n, m, str1, str2, dp);

        return dp[idx1][idx2] =
                   (takeStr1.size() < takeStr2.size()) ? takeStr1 : takeStr2;
        // we must explore both options and choose the one that results in the
        // smallest length.
    }

    string shortestCommonSupersequence(string str1, string str2) {
        // return call(0, 0, str1.size(), str2.size(), str1, str2); // recursion

        int n = str1.size(), m = str2.size();
        vector<vector<string>> dps(n + 1, vector<string>(m + 1, ""));
        // return memocall(0, 0, n, m, str1, str2, dps);  


        //Bottom up solution
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 1: Fill DP table using LCS logic
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0)
                    dp[i][j] = j; // If str1 is empty, take all of str2
                else if (j == 0)
                    dp[i][j] = i; // If str2 is empty, take all of str1
                else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] +1; 
                    // Match found, take diagonal value
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                     // Take min path
                }
            }
        }

        // Step 2: Backtrack to construct the SCS string
        int row = n, col = m;
        string subs = "";

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                subs += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                subs += str1[row - 1]; // Take from str1
                row--;
            } else {
                subs += str2[col - 1]; // Take from str2
                col--;
            }
        }

        // Step 3: Append remaining characters if any
        while (row > 0) {
            subs += str1[row - 1];
            row--;
        }
        while (col > 0) {
            subs += str2[col - 1];
            col--;
        }

        // Reverse to get correct order
        reverse(subs.begin(), subs.end());
        return subs;
    }
};

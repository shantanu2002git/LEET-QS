class Solution {
public:
    int res = 0;
    void fun(int ele, int n, vector<int>& vis) {
        if (ele > n) {
            res++;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && (ele % i == 0 || i % ele == 0)) {
                vis[i] = true;
                fun(ele + 1, n, vis);
                vis[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vist(n + 1, 0);
        fun(1, n, vist);
        return res;
    }
};
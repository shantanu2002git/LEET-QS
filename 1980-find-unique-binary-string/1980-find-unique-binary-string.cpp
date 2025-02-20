class Solution {
public:
    set<string> st;
    string ans = "";
    void call(int n, string res) {
        if (res.size() == n) {
            if (st.count(res) == 0) {
                ans = res;
            }
            return;
        }

        call(n, res + "0");
        call(n, res + "1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for (auto it : nums) {
            st.insert(it);
        }
        string res = "";
        call(nums.size(), res);
        return ans;
    }
};
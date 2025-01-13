class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int cnt = 0;
        map<char, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
            if (mpp[s[i]] > 2) {
                cnt = cnt + 2;
                mpp[s[i]] = mpp[s[i]] - 2;
            }
        }
        int ans = n - cnt;
        return ans;
    }
};

/*
class Solution {
public:
    int minimumLength(string s) {
        int res=0;
        unordered_map<char,int> m;
        for (int i = 0; i < s.size(); i++)m[s[i]]++;
        for(auto c:m) c.second%2==0?res+=2:res+=1;
        return res;
    }
};
*/
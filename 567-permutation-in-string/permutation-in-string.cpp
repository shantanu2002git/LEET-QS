class Solution {
public:
    bool call(string si, string s1) {
        set<char> st;
        vector<int>vl(26,0);
        for (auto i : si) {
            // st.insert(i);
            vl[i-'a']++;
        }
        for (auto j : s1) {
           vl[j-'a']--;
           if(vl[j-'a']<0){
            return 0;
           }
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        sort(s1.begin(), s1.end());
        for (int i = 0; i < n2; i++) {
            string si = s2.substr(i, n1);
            if (call(si, s1)) {
                cout<<s1<<" "<<si;
                return 1;
            }
        }
        return 0;
    }
};
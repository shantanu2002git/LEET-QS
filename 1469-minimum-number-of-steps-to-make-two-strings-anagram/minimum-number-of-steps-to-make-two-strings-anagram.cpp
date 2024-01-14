class Solution {
public:
    int minSteps(string s, string t) {
      map<char,int>mp1,mp2;
      for(int i=0; i<s.size(); i++){
          mp1[s[i]]++;
          mp2[t[i]]++;
      } 


 int s1 = 0;
        
        for (auto it : mp1) {
            char ch = it.first;
            if (mp2.find(ch) != mp2.end()) {
                s1 += max(0, mp1[ch] - mp2[ch]);
            } else {
                s1 += mp1[ch];
            }
        }

        return s1;
    }
};


/*
"leetcode", t = "practice" n=8
l=1        = 1
e=3   e=1  = 2
t=1   t=1  = 0
c=1   c=2  = -1 or 1
o=1        = 1
d=1        = 1

*/
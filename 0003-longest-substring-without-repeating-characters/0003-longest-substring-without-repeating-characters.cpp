class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int n=s.size(), i=0,j=0,res=0;
        while(i<n){
            mp[s[i]]++;


            while(mp.size()<(i-j+1)){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                }
                j++;
            }
            res=max(res, (i-j+1));
            i++;
        }
        return res;
    }
};
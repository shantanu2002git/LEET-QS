class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, int>mp;
        for(auto it : bannedWords){
            mp[it]++;
        }
        int c=0;
        for(auto it : message){
            if(c>=2){
                return true;
            }
            if(mp.find(it)!=mp.end()){
                c++;
            }
        }
        return false;
    }
};
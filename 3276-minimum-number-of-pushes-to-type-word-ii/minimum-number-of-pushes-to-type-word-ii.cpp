class Solution {
public:
    int minimumPushes(string word) {
        vector<int>frq(26,0);
        for( auto it : word){
            frq[it-'a']++;
        }
        int res=0;
        sort(frq.begin(),frq.end(),greater<int>());

        for(int i=0;i<26; i++){
            cout<<frq[i]<<" ";
           res=res+frq[i]*((i/8)+1);
        }
        return res;
    }
};
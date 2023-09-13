class Solution {
public:
    int minDeletions(string s) {
        map<char,int>cnt;
        unordered_set<int>frq;
        int del=0;
for(auto it : s){
    cnt[it]++;
}
for(auto i : cnt){
    int fq=i.second;
    while(fq>0 && frq.find(fq)!=frq.end()){
        fq--;
        del++;
    }
    frq.insert(fq);
}
return del;
    }
};
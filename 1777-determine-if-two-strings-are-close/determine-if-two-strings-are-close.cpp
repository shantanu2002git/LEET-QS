class Solution {
public:
    bool closeStrings(string wd1, string wd2) {
        int has1[26]={0};
        int has2[26]={0};
        for(int i=0; i<wd1.size(); i++){
            has1[wd1[i]-'a']++;
        }
        for(int j=0; j<wd2.size(); j++){
            has2[wd2[j]-'a']++;
        }
for(int i=0; i<26; i++){
    if(has1[i]==0 && has2[i]!=0 || has1[i]!=0 && has2[i]==0){
        return 0;
    }
}
    sort(has1,has1+26);
    sort(has2,has2+26);
    for(int i=0;i<26;i++){
            if(has1[i]!=has2[i]) return false;
        }
        return true;


    }
};
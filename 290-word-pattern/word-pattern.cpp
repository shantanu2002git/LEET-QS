class Solution {
public:
    bool wordPattern(string pat, string s) {
       map<char,string>mp1;
       map<string,char>mp2;
       int i=0,j=0,n=pat.size(),m=s.size();
       while(i<n && j<m){
          string si="";
          while(j<m && s[j]!=' '){
              si=si+s[j++];
          }
          j++;

if(mp1.count(pat[i]) ){
    if(mp1[pat[i]]!=si) return false;
}

if(mp2.count(si)){
    if(mp2[si]!=pat[i]) return false;
}

          mp1[pat[i]]=si;
          mp2[si]=pat[i];
          i++;
       }

       if(j<m || i<n){
           return false;
       }
       return true;
    }
};
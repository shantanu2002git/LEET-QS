class Solution {
public:
    bool halvesAreAlike(string s) {
     int n=s.size();
     int md=n/2,c1=0,c2=0;
     set<char>st{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
for(int i=0; i<n; i++){
if(st.count(s[i]) && i<md){
    c1++;
}if(st.count(s[i]) && i>=md){
    c2++;
}
}

return c1==c2;
    }
};
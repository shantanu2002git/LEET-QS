class Solution {
public:
    int minSteps(string s, string t) {
       map<char,int>mp1,mp2;
       for(auto it : s){
           mp1[it]++;
       } 
       int n=s.size();
for(auto it : t){
if(mp1[it]>0){
    mp1[it]--;
    n--;
}else{
    n++;
}
}
return n;
    }
};

/*
"leetcode", t = "coats" n=8 , m=5
l=1        = 
e=3        = 
t=1    t=1    = 0
c=1    c=1    = 0
o=1    o=1    = 0
d=1        =           ....a,s.....
*/
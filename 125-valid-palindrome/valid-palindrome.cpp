class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,n=s.size();
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(i<n){
           if(!isalnum(s[i])){
               i++;
           }
           else if(!isalnum(s[n])){
               n--;
           }
           else{
         if(s[i]!=s[n]){
               return 0;
           }
         i++,n--;
           }
         
        }
        return 1;
    }
};
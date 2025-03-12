class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n  = word.length();
        
        int i = 0;
        int ans = 0;
        
        while(i<n){
            int ac = 0;
            int ec = 0;
            int ic = 0;
            int oc = 0;
            int uc = 0;
            
            while(i<n && word[i]=='a'){
                ac++;
                i++;
            }
            
            while(i<n && word[i]=='e'){
                ec++;
                i++;
            }
            
            while(i<n && word[i]=='i'){
                ic++;
                i++;
            }
            
            while(i<n && word[i]=='o'){
                oc++;
                i++;
            }
            
            while(i<n && word[i]=='u'){
                uc++;
                i++;
            }
            
            if(ac>0 && ec>0 && ic>0 && oc>0 && uc>0){
                ans = max(ans, ac+ec+ic+oc+uc);
            }
        }
        
        return ans;
    }
};
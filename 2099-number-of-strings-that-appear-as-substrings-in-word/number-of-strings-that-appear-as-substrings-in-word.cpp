class Solution {
public:
    int numOfStrings(vector<string>& p, string word) {
        int n=p.size(),c=0;
        for(auto it : p){
            if(word.find(it)!=-1){
                c++;
            }
        }
        return c;
    }
};
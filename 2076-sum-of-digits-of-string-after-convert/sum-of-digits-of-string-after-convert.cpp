class Solution {
public:
    int getLucky(string s, int k) {
        string tem="";
        string ins="";
        for(int i=0; i<s.size();i++){
ins=ins+to_string(s[i]-'a'+1);
        }
        while(k>0)
        {
            int ti=0;
            for(char c : ins){
                ti=ti+(c-'0');
            }
            ins=to_string(ti);
            k--;
        }
        return stoi(ins);
    }
};
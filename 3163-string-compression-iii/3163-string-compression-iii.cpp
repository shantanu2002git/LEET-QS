class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size(),i=0;
        
        while (i < n) {
            char c = word[i];
            int count = 0;
            
            while (i < n && word[i] == c && count < 9) {
                count++;
                i++;
            }
          comp.append(to_string(count));
            comp.push_back(c);
        }
        
        return comp;
    }
};

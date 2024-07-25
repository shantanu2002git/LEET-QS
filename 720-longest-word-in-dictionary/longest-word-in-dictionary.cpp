class Solution {
public:
    string longestWord(vector<string>& words) {
       
        unordered_set<string> wordSet(words.begin(), words.end());
        
        string res = "";
      
        for (const string& word : words) {
            bool isValid = true;
            string prefix = "";
          
            for (char ch : word) {
                prefix += ch;
                if (wordSet.find(prefix) == wordSet.end()) {
                    isValid = false;
                    break;
                }
            }
            
           if (isValid) {
                if (word.size() > res.size() || (word.size() == res.size() && word < res)) {
                    res = word;
                }
            }
        }
        
        return res;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         unordered_map<string, int> prefixCount;
    
    for (int x : arr1) {
        string strX = to_string(x);
        for (int i = 1; i <= strX.length(); i++) {
            string prefix = strX.substr(0, i);
            prefixCount[prefix]++;
        }
    }
    
    int longestPrefix = 0;
    
    for (int y : arr2) {
        string strY = to_string(y);
        for (int i = 1; i <= strY.length(); i++) {
            string prefix = strY.substr(0, i);
            if (prefixCount.find(prefix) != prefixCount.end()) {
                longestPrefix = max(longestPrefix, i);
            }
        }
    }
    
    return longestPrefix;
    }
};
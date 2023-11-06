class Solution
{
public:
    int minDistance(string word1, string word2)
    
    {      
        int n = word1.size(), m = word2.size();
        
        // Initialize dp with size (n+1) x (m+1) to avoid buffer overflow
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return minDistanceRecur(word1, word2, word1.size(), word2.size(), dp);
    }

    int minDistanceRecur(string word1, string word2, int word1Index, int word2Index,  vector<vector<int>>& dp)
    {
        // Base cases
        if (word1Index == 0)
        {
            return word2Index;
        }
        if (word2Index == 0)
        {
            return word1Index;
        }
        
        // Check if result is already computed
        if (dp[word1Index][word2Index] != -1){
            return dp[word1Index][word2Index];
        }
        
        // Recursive cases
        if (word1[word1Index - 1] == word2[word2Index - 1])
        {
            // Characters match, no operation needed
            return minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1, dp);
        }
        else
        {
            // Characters don't match, find minimum distance using insert, delete, or replace operations
            int insertOperation = minDistanceRecur(word1, word2, word1Index, word2Index - 1, dp);
            int deleteOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index, dp);
            int replaceOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1, dp);
            int minDist = min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
            
            // Store result in dp for future use
            dp[word1Index][word2Index] = minDist;
            
            return minDist;
        }
    }
};

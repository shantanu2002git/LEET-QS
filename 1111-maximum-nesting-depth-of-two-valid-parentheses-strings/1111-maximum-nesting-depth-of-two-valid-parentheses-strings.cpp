class Solution {
public:
   // Function to check if a string is a valid parentheses string
bool isValid(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) return false; // More closing than opening
    }
    return balance == 0; // Must be balanced at the end
}

// Function to calculate the nesting depth of a string
int calculateDepth(const string& s) {
    int depth = 0, maxDepth = 0;
    for (char c : s) {
        if (c == '(') {
            depth++;
            maxDepth = max(maxDepth, depth);
        } else {
            depth--;
        }
    }
    return maxDepth;
}

// Function to create the answer array based on the mask
vector<int> createAnswerArray(int mask, int n) {
    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
        answer[i] = (mask & (1 << i)) ? 0 : 1; // 0 for A, 1 for B
    }
    return answer;
}

// Main function to find the optimal split
vector<int> maxDepthAfterSplit(string seq) {
    int n = seq.length();
    int minMaxDepth = INT_MAX;
    vector<int> bestSplit;

    // Iterate through all possible splits using bitmasking
    for (int mask = 0; mask < (1 << n); ++mask) {
        string A, B;

        // Create subsequences A and B based on the current mask
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                A += seq[i]; // Add to A
            } else {
                B += seq[i]; // Add to B
            }
        }

        // Check if A and B are valid parentheses strings
        if (isValid(A) && isValid(B)) {
            int depthA = calculateDepth(A);
            int depthB = calculateDepth(B);
            int maxDepth = max(depthA, depthB);

            // Update minimum maximum depth and best split
            if (maxDepth < minMaxDepth) {
                minMaxDepth = maxDepth;
                bestSplit = createAnswerArray(mask, n);
            }
        }
    }

    return bestSplit;
}
};
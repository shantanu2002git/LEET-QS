class Solution {
public:


int fact[8];
set<string> have; // To store unique sequences

void computeFactorial() {
    fact[0] = 1;
    for (int i = 1; i <= 7; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

// Compute permutations considering duplicate characters
int pcombination(string si) {
    int n = si.size();
    map<char, int> mp;

    for (char ch : si) {
        mp[ch]++;
    }

    int totalen_fact = fact[n]; // Factorial of total length
    for (auto it : mp) {
        totalen_fact /= fact[it.second]; // Divide by duplicate counts
    }
    return totalen_fact;
}

// Recursively generate all subsequences and count permutations
int call(string& tiles, int idx, int n, string si) {
    if (idx >= n) {
        if (have.find(si) != have.end()) return 0; // Avoid duplicate counting
        have.insert(si);
        return pcombination(si); // Count unique permutations
    }

    // Include current character
    int include = call(tiles, idx + 1, n, si + tiles[idx]);

    // Exclude current character
    int exclude = call(tiles, idx + 1, n, si);

    return include + exclude;
}

int numTilePossibilities(string tiles) {
    computeFactorial(); 
    sort(tiles.begin(), tiles.end()); // Sort to handle duplicates
    return call(tiles, 0, tiles.size(), "")-1;
}



};
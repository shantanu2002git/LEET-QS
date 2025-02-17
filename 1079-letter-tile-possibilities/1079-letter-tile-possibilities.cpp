class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for (char tile : tiles) {
            count[tile - 'A']++;
        }
        return dfs(count);
    }

private:
    int dfs(vector<int>& count) {
        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) continue;
            sum++;
            count[i]--;
            sum += dfs(count);
            count[i]++;
        }
        return sum;
    }
};



/*
abc
a b c ab bc abc : ba cb cba : 

[abc]
acb
[cba]
bac
bca
cab


(2*(n*(n+1)/2)-n)-n!-2 */
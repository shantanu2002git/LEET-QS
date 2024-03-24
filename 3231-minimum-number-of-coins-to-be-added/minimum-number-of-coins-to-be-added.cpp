class Solution {
public:
    int minimumAddedCoins(std::vector<int>& coins, int target) {
        int opt = 0, add = 0;
        std::sort(coins.begin(), coins.end());
        
        for (auto i : coins) {
            while (i > opt + 1) { //[ think there is no need to add any extra coin ] so opt=0
                add++;
                opt = opt + (opt + 1); // Add the next coin that fills the gap
                if (opt >= target) {
                    return add;
                }
            }
            opt = opt + i;
            if (opt >= target) {
                return add;
            }
        }
        
        while (opt < target) {
            add++;
            opt = opt + (opt + 1); 
        // Add the next coin that fills the gap
        }
        
        return add;
    }
};

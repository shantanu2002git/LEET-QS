#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Map to store number-index pairs

    
        for (int i = 0; i < nums.size(); i++) {
            int extra = target - nums[i];
            if (mp.find(extra) != mp.end()) {
                return {mp[extra], i};
            }
            mp[nums[i]] = i;
        }
        
     
        return {};
    }
};

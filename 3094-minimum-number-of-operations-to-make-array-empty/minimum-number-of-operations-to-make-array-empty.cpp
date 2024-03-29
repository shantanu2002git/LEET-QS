class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int ans=0,l=0;
        for(auto it : mp){
          if(it.second==1) return -1;
            int times=it.second;
            
            if(times%3==0){
                ans+=times/3;
            }
            else{
                ans+=times/3+1;
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    int minOperations(vector<int>& nums) {
       
    unordered_map<int, int> v;
    int ans = 0;

    for (int x : nums) {
        v[x]++;
    }

    for (auto& [x, y] : v) {
        if (y == 1) {
            return -1;
        } 
        else {
            ans = ans + ((y+ 2) / 3);
        }
    }

    return ans;
    }
};
*/
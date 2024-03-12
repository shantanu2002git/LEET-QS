class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>odd,even;
        int omax=0,emax=0,somax=0,semax=0,oval,eval;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
            even[nums[i]]+=1;
            else odd[nums[i]]+=1;
        }
        for(auto i:odd) if(i.second>omax){ omax=i.second; oval=i.first;}           
        for(auto i:even)if(i.second>emax){ emax=i.second; eval=i.first; }


        for(auto i:odd) if(i.first!=oval) somax=max(i.second,somax);
        for(auto i:even) if(i.first!=eval) semax=max(i.second,semax);

        
        if(oval!=eval) return  nums.size()-omax-emax;  
        return min(nums.size()-somax-emax,nums.size()-omax-semax);
    }
};
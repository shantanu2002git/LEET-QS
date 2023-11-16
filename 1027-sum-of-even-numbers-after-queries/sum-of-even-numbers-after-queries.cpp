class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &qre)
    {
        int n = nums.size();
        int evs = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                evs = evs + nums[i];
            }
        }
        vector<int> res;
        for (auto it : qre)
        {
            int vl = it[0], idx = it[1];
            if (nums[idx] % 2 == 0 && vl % 2 == 0) //ev==ev
            {
                evs = evs + vl;
            }
           else if (nums[idx] % 2 != 0 && vl % 2 != 0)//od==od
            {
                evs += (nums[idx] + vl);
            }
            else if(nums[idx]%2==0 && vl%2!=0){ // ev==od
                evs=evs-nums[idx];
                
            }
            else if(nums[idx]%2!=0 && vl%2==0){ //od==ev

             if ((nums[idx] + vl) % 2 == 0)
        {
            if(vl<0){
 evs=evs+(vl);
            }else{
                evs=evs-vl;
            }
               
            }
            }
            res.push_back(evs);
             nums[idx] += vl;
        }
        return res;
    }
};
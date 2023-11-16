class Solution
{
public:
int cal(vector<int>arr, int div){
    int si=0;
    for(int i=0; i<arr.size(); i++){
si=si+ceil((double)arr[i]/div);
    }
    return si;
}
    int smallestDivisor(vector<int> &nums, int th)
    {
        /* int s=0,n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=1; i<mx; i++){
            int si=0;
            for(int j=0; j<n; j++){
                  si=si+ceil((double)nums[j]/i);
            }
            if(si<=th){
                return i;
            }
        }
        return mx;
*/

        int st = 1, en = *max_element(nums.begin(), nums.end());
        while (st <= en)
        {
            int mid = (st + en) / 2;

            int vl = cal(nums, mid);
            if (vl > th)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }
        return st;
    }
};
class Solution {
public:
    const int mod=1e9+7;
    int numberOfWays(string corridor) {
        int seats=0;
        int plants=0;
        long div=1;
        for(auto itr:corridor)
        {
            if(itr=='S')
            {
                seats+=1;
            }
            if(seats==2 && itr=='P')
            {
                plants+=1;
            }
            if(seats==3)
            {
               div*=(plants+1);
               div%=mod;
               plants=0;
               seats=1;
            }

        }
        if(seats<2)
        {
            return 0;
        }
        return div;
    }
};
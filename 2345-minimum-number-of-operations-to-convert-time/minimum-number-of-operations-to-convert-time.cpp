class Solution {
public:
    int convertTime(string cu, string co) {
        string cu_hu = cu.substr(0, 2), cu_m = cu.substr(3);
        string so_hu = co.substr(0, 2), so_mi = co.substr(3);

       int cuhh = stoi(cu_hu);
       int  cohh = stoi(so_hu);


       int  cumm = stoi(cu_m);
       int  comm = stoi(so_mi);

      
        /*
        current = "02:30", correct = "04:35"
        150 - 275
        >> 125/60 =2 >> 5 /5 >> 1 =(2+1)=3
        */
        int dif = (cuhh * 60 + cumm) - (cohh * 60 + comm);  // mint differeance :
        int tim[4] = {60, 15, 5, 1};
        int res = 0;
        for (auto it : tim) {
            res = res + dif / it;
            dif = dif % it;
        }

        return abs(res);
    }
};
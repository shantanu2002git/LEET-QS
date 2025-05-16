class Solution {
public:
    bool call(int ele, vector<int>& cit) {
        int n=cit.size(), i = 0, j = n - 1;

        while (i <= j) {
            int md = (i + j) / 2;
            if (cit[md] >= ele) {
                j = md - 1;
            } else {
                i = md + 1;
            }
        }

        return (n - i >= ele);
    }

    int hIndex(vector<int>& cit) {
        sort(cit.begin(), cit.end());
        int res = 0, n = cit.size();
        for (int i = 1; i <= n; i++) {
            if (call(i, cit)) {
                res = i;
            }else{
                break;
            }
        }
        return res;
    }
};


/*
[3,0,6,1,5]

1 : 3 6 5
2 : 3 6 5
3 : 3 6 5

4 : 5 6

sort : 0 1 3 5 6   n=5 
l    |    r  | md  | ele = 1
0         5  | (0+5)/2 : 2 :  3  



if (index<=(count_greater_element)){
    res++;
}


*/
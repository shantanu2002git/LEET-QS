class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int st = 0, j = cp.size() - 1, mx = 0;
        for (int i = 0; i < k; i++) {
            st = st + cp[i];
        }
        cout<<st<<endl;
      int  i = k-1;
        while (i >= 0) {
            mx = max(mx, st);
            st = st - cp[i];
            cout<<st<<" "<<i<<endl;
            i--;
            st = st + cp[j];
            cout<<st<<" "<<j<<endl;
            j--;
        }
         mx = max(mx, st);
        return mx;
    }
};
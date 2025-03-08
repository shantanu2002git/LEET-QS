class Solution {
public:
    vector<int> prime_seive(int left,int right) {
        vector<int> prime;
        vector<bool> numlist(right + 1, 1);
        numlist[0] = numlist[1] = 0;
        for (int i = 2; i * i <= right; i++) {
            if (numlist[i]) {
                for (int j = i * i; j <= right; j = j + i) {
                    numlist[j] = 0;
                }
            }
        }
        for (int l = 0; l <= right; l++) {
            if (numlist[l] && l>=left) {
                prime.push_back(l);
            }
        }

        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primerange = prime_seive(left,right);

        for (auto it : primerange) {
            cout << it << " ";
        }
        int n1 = -1, n2 = -1, res = 1e9;
        for (int i = 1; i < primerange.size(); i++) {
            if (res > ((primerange[i] - primerange[i - 1]))){
                res = (primerange[i] - primerange[i - 1]);
                n1=primerange[i-1];
                n2=primerange[i];
                
                }
        }
        return {n1,n2};
    }
};
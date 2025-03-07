class Solution {
public:
    vector<int> sieve(int left, int right) {
        vector<int> isprime(right + 1, 1);
        vector<int> rangeprim;

        // Mark 0 and 1 as non-prime
        isprime[0] = isprime[1] = 0;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= right; i++) {
            if (isprime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isprime[j] = 0;
                }
            }
        }

        // Collect prime numbers in range [left, right]
        for (int i = left; i <= right; i++) {
            if (isprime[i]) {
                rangeprim.push_back(i);
            }
        }

        return rangeprim;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primerange = sieve(left, right);

        if (primerange.size() < 2) {
            return {-1, -1};  // If no pairs exist, return [-1, -1]
        }

        int n1 = -1, n2 = -1, mini = INT_MAX;
        for (int i = 0; i < primerange.size() - 1; i++) {
            int diff = primerange[i + 1] - primerange[i];
            if (diff < mini) {
                mini = diff;
                n1 = primerange[i];
                n2 = primerange[i + 1];
            }
        }

        return {n1, n2};
    }
};

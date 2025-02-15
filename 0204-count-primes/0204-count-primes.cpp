class Solution {
public:
    int sieve(int n, vector<bool>& prime) {
        if (n <= 2) return 0; 

        prime[0] = prime[1] = false;  // 0 and 1 are not prime
        int res = 0;  // Count of prime numbers

        for (int i = 2; i * i < n; i++) {   //sqrt n
            if (prime[i]) {  
                for (int j = i * i; j < n; j += i) {   //n lg log n
                    prime[j] = false;  // Mark non-prime numbers
                }
            }
        }

    //TC= sqrt(n)+n log log n = n log log n
    
        for (int i = 2; i < n; i++) {
            if (prime[i]) res++;  
        }
        return res;
    }

    int countPrimes(int n) {
        vector<bool> prime(n, true);
        return sieve(n, prime);
    }
};

class Solution {
public: 
// { nextGreaterElement === nextPermutation }
    int nextGreaterElement(int n) {
        string dig=to_string(n);
        next_permutation(dig.begin(),dig.end());

        auto lld=stoll(dig);

        return (lld>INT_MAX || lld<=n) ? -1 : lld;
    }
};
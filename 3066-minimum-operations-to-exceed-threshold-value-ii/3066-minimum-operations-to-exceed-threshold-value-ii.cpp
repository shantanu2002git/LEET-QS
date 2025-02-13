#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (auto it : nums) {
            pq.push(it);
        }
        ll res = 0;
        while (pq.top() < k) {
            ll tp1 = pq.top();
            pq.pop();
            ll tp2 = pq.top();
            pq.pop();
            ll tp = min(tp1, tp2) * 2 + max(tp1, tp2);
            pq.push(tp);
            res++;
        }
        return res;
    }
};

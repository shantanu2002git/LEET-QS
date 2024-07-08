class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<pair<long long, int>> q;
        for (int i = 0; i < gifts.size(); i++) {
            q.push({gifts[i], i});
        }
        while (k--) {
            auto tp = q.top();
            q.pop();
            int ix = tp.second, vl = tp.first;
           q.push( {sqrt(vl),1});
        }
        long long s = 0;
       while(!q.empty()) {
             auto tp = q.top();
            q.pop();
            int ix = tp.second, vl = tp.first;
            s = s + vl;
        }
        return s;
    }
};
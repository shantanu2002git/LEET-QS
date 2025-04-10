class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (auto i : tasks) {
            mp[i]++;
        }
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        int res = 0;
        while (!pq.empty()) {

            vector<pair<int, char>> keep;
            int time = n;
            while (time--) {
                if (!pq.empty()) {
                    auto [fq, ci] = pq.top();
                    if (fq >= 1) {
                        keep.push_back({fq - 1, ci});
                    }

                    pq.pop();
                }

                res++;
            }
            for(auto it : keep){
                pq.push({it.first, it.second});
            }
        }
        return res;
    }
};
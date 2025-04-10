class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) freq[task]++;

        priority_queue<int> pq;
        for (auto [ch, count] : freq) pq.push(count);

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            // Process up to (n + 1) tasks in a cycle
            while (cycle-- && !pq.empty()) {
                int cnt = pq.top(); pq.pop();
                if (--cnt > 0) temp.push_back(cnt);
                time++;
            }

            // Push remaining back to heap
            for (int cnt : temp) pq.push(cnt);

            // If tasks left, we were idle
            if (!pq.empty()) time += cycle + 1;
        }

        return time;
    }
};

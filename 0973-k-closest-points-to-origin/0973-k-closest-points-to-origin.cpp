class Solution {
public:
    struct Compare {
        bool operator()(const tuple<int, int, int>& a,
                        const tuple<int, int, int>& b) {
            return a > b;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pt;

        for (auto it : points) {
            pt.push({((it[0] * it[0]) + (it[1] * it[1])), it[0], it[1]});
        }

        while (!pt.empty() && k--) {
            auto [dist, x, y] = pt.top();
            pt.pop();
            res.push_back({x, y});
        }

        return res;
    }
};

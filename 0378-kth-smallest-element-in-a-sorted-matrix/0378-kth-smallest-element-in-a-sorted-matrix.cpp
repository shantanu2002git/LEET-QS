class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : matrix) {
            for (auto i : it) {
                pq.push(i);
                cout << i << "  ";
            }
        }
        k = k - 1;
        while (k-- && !pq.empty()) {
            cout << pq.top() << "-";
            pq.pop();
        }
        return pq.top();
    }
};
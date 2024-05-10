class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float, pair<int, int>>> vp;
        vector<int> res;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                float dv = ((float)arr[i] / (float)arr[j]);
                vp.push_back({dv, {arr[i], arr[j]}});
                // cout << dv << " ";
            }
        }
        sort(vp.begin(), vp.end());
        int x = vp[k - 1].second.first;
        int y = vp[k - 1].second.second;
        return {x, y};
    }
};
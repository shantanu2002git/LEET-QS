class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n, 0);
        queue<int>q;
        q.push(0);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto it = q.front();
                q.pop();
                if (vis[it] == 1) {
                    continue;
                }
                vis[it] = 1;
                for (auto i : rooms[it]) {
                    q.push(i);
                }
            }
        }
        for(auto k : vis){
            if(k==0){
                return 0;
            }
        }
        return 1;
    }
};
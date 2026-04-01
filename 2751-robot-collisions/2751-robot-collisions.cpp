class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hea, string dir) {
        int n = pos.size();

        // store: position, health, direction, original index
        vector<tuple<int,int,char,int>> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back({pos[i], hea[i], dir[i], i});
        }

        // sort by position
        sort(robots.begin(), robots.end());

        stack<int> st; // indices of robots
        vector<int> health(n);

        for (int i = 0; i < n; i++) {
            health[i] = get<1>(robots[i]);
        }

        for (int i = 0; i < n; i++) {
            char d = get<2>(robots[i]);

            if (d == 'R') {
                st.push(i);
            } else {
                // collision with previous R robots
                while (!st.empty() && health[i] > 0) {
                    int j = st.top();

                    if (health[j] < health[i]) {
                        st.pop();
                        health[i]--;
                        health[j] = 0;
                    } 
                    else if (health[j] > health[i]) {
                        health[j]--;
                        health[i] = 0;
                        break;
                    } 
                    else {
                        // equal
                        st.pop();
                        health[j] = 0;
                        health[i] = 0;
                        break;
                    }
                }
            }
        }

        // collect survivors
        vector<pair<int,int>> survivors;

        for (int i = 0; i < n; i++) {
            if (health[i] > 0) {
                survivors.push_back({get<3>(robots[i]), health[i]});
            }
        }

        // sort by original index
        sort(survivors.begin(), survivors.end());

        vector<int> res;
        for (auto &p : survivors) {
            res.push_back(p.second);
        }

        return res;
    }
};
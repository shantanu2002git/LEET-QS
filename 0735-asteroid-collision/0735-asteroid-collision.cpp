class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        int n = asteroids.size(), x = 0;
        for (auto it : asteroids) {
            bool flg = 1;

            while (!st.empty() && st.top() > 0 && it < 0) {
                if (abs(st.top()) < abs(it)) {
                    st.pop();
                    continue;
                }
                cout << "In" << endl;
                if (abs(st.top()) == abs(it)) {
                    st.pop();
                }
                flg = 0;
                break;
            }

            if (flg) {
                st.push(it);
            }
        }

        vector<int> lastas(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            lastas[i] = st.top();
            st.pop();
        }
        return lastas;
    }
};
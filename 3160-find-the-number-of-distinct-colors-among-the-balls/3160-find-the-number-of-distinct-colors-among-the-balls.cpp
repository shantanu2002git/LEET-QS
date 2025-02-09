/*
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &qui)
    {

        map<int, int> ball, color;
        set<int> balls, colors;
        map<int, int> memory;
        vector<int> res;
        int cnt = 0, nc=0;;
        for (auto it : qui)
        {

            if (ball.find(it[0]) != ball.end())
            {
                auto itc = ball[it[0]];
                ball[it[0]] = it[1];
            }
            if (color.find(it[1]) != color.end())
            {
                auto itb = color[it[1]];
                ball[itb] = it[1];
            }

            if (ball.find(it[0]) == ball.end() && color.find(it[1]) == color.end())
            {
                cnt++;
                ball[it[0]] += it[1];
                color[it[1]] += it[0];
            }
            res.push_back(ball.size());
        }
        for (auto ti : ball)
        {
            cout << ti.first << " " << ti.second << endl;
        }
        cout << endl;
        // for (auto ti : color)
        // {
        //     cout << ti.first << " " << ti.second<<endl;
        // }
        cout << endl;

        return res;
    }
};
*/

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap, ballMap;

        for (int i = 0; i < n; i++)
        {
            int ball = queries[i][0], color = queries[i][1];
            if (ballMap.find(ball) != ballMap.end())
            {
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;
                if (colorMap[prevColor] == 0)
                    colorMap.erase(prevColor);
            }
            ballMap[ball] = color;

            colorMap[color]++;

            result[i] = colorMap.size();
        }

        return result;
    }
};

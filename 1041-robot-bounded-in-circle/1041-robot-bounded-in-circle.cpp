struct inst
{
    string go;
    int xi;
    int xj;
};

class Solution
{
public:
    bool isRobotBounded(string ins)
    {
        int n = ins.size();

        vector<inst> path;
        path.push_back({"N", 0, 0});

        for (int i = 0; i < n; i++)
        {
            auto it = path.back();
            string nexp = it.go;
            int x = it.xi, y = it.xj;
            if (ins[i] == 'G' && nexp == "N")
            {
                path.push_back({"N", x, y + 1});
            }
            if (ins[i] == 'G' && nexp == "S")
            {
                path.push_back({"S", x, y - 1});
            }
            if (ins[i] == 'G' && nexp == "E")
            {
                path.push_back({"E", x + 1, y});
            }
            if (ins[i] == 'G' && nexp == "W")
            {
                path.push_back({"W", x - 1, y});
            }
            if (ins[i] == 'L')
            {
                if (nexp == "N")
                    path.push_back({"W", x, y});
                else if (nexp == "W")
                    path.push_back({"S", x, y});
                else if (nexp == "S")
                    path.push_back({"E", x, y});
                else if (nexp == "E")
                    path.push_back({"N", x, y});
            }
            if (ins[i] == 'R')
            {
                if (nexp == "N")
                    path.push_back({"E", x, y});
                else if (nexp == "E")
                    path.push_back({"S", x, y});
                else if (nexp == "S")
                    path.push_back({"W", x, y});
                else if (nexp == "W")
                    path.push_back({"N", x, y});
            }
        }
        auto final = path.back();
        if ((final.xi == 0 && final.xj == 0) || ((final.go != "N")))
        {
            return true;
        }
        return false;
    }
};
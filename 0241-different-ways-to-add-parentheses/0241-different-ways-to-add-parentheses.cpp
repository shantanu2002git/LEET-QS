class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> totalres;
        int n = exp.size();
        if (n == 1)
            return {stoi(exp)};

        for (int i = 0; i < n; i++) {
            char sign = exp[i];
            if (isdigit(sign))
                continue;
            vector<int> left = diffWaysToCompute(exp.substr(0, i));
            vector<int> right = diffWaysToCompute(exp.substr(i + 1));

            for (auto l : left) {
                for (auto r : right) {
                    int res = 0;
                    switch (sign) {
                    case '+':
                        res = l + r;
                        break;
                    case '-':
                        res = l - r;
                        break;
                    case '*':
                        res = l * r;
                        break;
                    }
                    totalres.push_back(res);
                }
            }
        }
        return totalres;
    }
};
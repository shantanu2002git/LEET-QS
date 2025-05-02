class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);  // Maximum possible size

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;

                int sum = mul + res[pos2];
                res[pos2] = sum % 10;
                res[pos1] += sum / 10;  // carry added to the left
            }
        }

        string result = "";
        for (int num : res) {
            if (!(result.empty() && num == 0))  // skip leading 0s
                result += (num + '0');
        }

        return result.empty() ? "0" : result;
    }
};

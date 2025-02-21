class Solution {
public:
    string maskPII(string s) {
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int lsc = -1;
        int phnum = 0;
        string sph = "";
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                phnum++;
                sph = sph + s[i];
            }
            if (s[i] == '@') {
                lsc = i;
                cout << s[lsc] << "----";
                break;
            }
        }
        if (lsc != -1) {
            string emil_1f =
                s.substr(0, 1) + "*****" + s.substr(lsc - 1, 1) + s.substr(lsc);
            return emil_1f;
        }

        else {
            int exlen = (phnum - 10);
            n = sph.size();
            switch (exlen) {
            case 0:
                return "***-***-" + sph.substr(n - 4);
                break;
            case 1:
                return "+*-***-***-" + sph.substr(n - 4);
                break;
            case 2:
                return "+**-***-***-" + sph.substr(n - 4);
                break;
            case 3:
                return "+***-***-***-" + sph.substr(n - 4);

            default:
                "NO";
            }
        }
        return "...";
    }
};

//"1(234)567-890"
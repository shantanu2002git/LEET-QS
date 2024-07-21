class Solution {
public:
    int minInsertions(string s) {
        int add = 0, cls = 0;
        for (auto i : s) {
            if (i == '(') {
                cls = cls + 2;
                if (cls % 2 != 0) {
                    add++;
                    cls--;
                }
            } else {
                if (cls == 0) {
                    add++;
                    cls++;
                } else {
                    cls--;
                }
            }
        }
        return add + cls;
    }
};
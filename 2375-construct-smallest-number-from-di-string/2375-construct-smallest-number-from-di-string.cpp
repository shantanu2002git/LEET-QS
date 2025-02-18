class Solution {
public:
    // vector<bool>visit(10, 0);
    bool visit[10]={0};
    void call(string pat, int idx, string res) {
        if(idx>=pat.size()){
            return ;
        }

        for (int i = 1; i <= 9; i++) {
            if (pat[idx] == 'I') {
                if(res.empty()){
                      res=res+to_string(i);
                    visit[i] = 1;
                    call(pat, idx + 1, res);
                }
                else if (visit[i] == 0 && res.back() - '0' < i) {
                    res=res+to_string(i);
                    visit[i] = 1;
                    call(pat, idx + 1, res);
                }
            } else {
                if(res.empty()){
                      res=res+to_string(i);
                    visit[i] = 1;
                    call(pat, idx + 1, res);
                }
                else if(visit[i] == 0 && res.back() - '0' > i) {
                    // res.push_back(to_string(i));
                     res=res+to_string(i);
                    visit[i] = 1;
                    call(pat, idx + 1, res);
                }
            }
            res.pop_back();
            visit[i] = 0;
        }
    }
    string smallestNumber(string pattern) {
        string res="";
        call(pattern, 0, res);
        return res;
    }
};
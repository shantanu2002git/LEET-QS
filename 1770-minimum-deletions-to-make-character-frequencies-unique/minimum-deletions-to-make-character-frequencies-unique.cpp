#include <string>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int c = 0;
        priority_queue<int> pq;
        for(auto it : mp) {
            pq.push(it.second);
        }
        while(!pq.empty()) {
            int tp1 = pq.top();
            pq.pop();
            if(!pq.empty()) {
                int tp2 = pq.top();
                if(tp1 == tp2 && tp1 > 0) {
                    c++;
                    tp1--;
                    pq.push(tp1);
                }
            }
        }
        return c;
    }
};

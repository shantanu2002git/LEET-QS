class Solution {
private:
    void dfs(vector<int>& digits, set<int>& visited, int x, int step){
        visited.insert(x);
        if(step==2){
            return;
        }
        for(int i = 0; i < digits.size(); ++i){
            for(int j = i+1; j < digits.size(); ++j){
                if(digits[i]==digits[j]) continue;
                int x_ = x + (digits[j]-digits[i])*div[i] + (digits[i]-digits[j])*div[j];
                swap(digits[i], digits[j]);
                dfs(digits, visited, x_, step+1);
                swap(digits[i], digits[j]);
            }
        }
    }
private:
    vector<int> query_digits(int x){
        vector<int> v(MAX_D, 0);
        for(int i = 0; i < MAX_D; ++i){
            v[i] = x%10;
            x/=10;
        }
        return v;
    }
    
    void construct(){
        div = vector<int>(MAX_D, 1);
        for(int i = 1; i < div.size(); ++i){
            div[i] = div[i-1] * 10;
        }
    }
    
    void visit(int x){
        vector<int> digits = query_digits(x);
        set<int> visited;
        dfs(digits, visited, x, 0);
        for(auto v : visited){
            counts[v]++;
        }
    }
    
public:
    int countPairs(vector<int>& nums) {
        construct();
        int ret = 0;
        for(auto x: nums){
            ret += counts[x];
            visit(x);
        }
        return ret;
    }
private:
const int MAX_D = 7;
vector<int> div;
unordered_map<int, int> counts;
};
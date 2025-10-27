class Bank {
public:
    vector<long long> bal;
    int n = 0;
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool vaild(int accidx) { return (accidx > 0 && accidx <= n); }

    bool transfer(int fromacc, int toacc, long long money) {
        if (!vaild(fromacc) || !vaild(toacc) || bal[fromacc - 1] < money)
            return false;
        bal[fromacc - 1] = bal[fromacc - 1] - money;
        bal[toacc - 1] = bal[toacc - 1] + money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!vaild(account))
            return false;
        bal[account - 1] = bal[account - 1] + money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!vaild(account) || bal[account - 1] < money)
            return false;
        bal[account - 1] = bal[account - 1] - money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
class MyCalendarTwo {
public:
    map<int, int> record;
    int maxlapping = 2;
    MyCalendarTwo() {  }

    bool book(int st, int en) {
        record[st]++;
        record[en]--;

        int overll = 0;
        for (auto it : record) {
            overll = overll + it.second;
            if (overll > maxlapping) {
                record[st]--;
                record[en]++;
                if (record[st] == 0) {
                    record.erase(st);
                }
                if (record[en] == 0) {
                    record.erase(en);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

class period {
public:
    int start, end;
    period(int st, int en) {
        start = st;
        end = en;
    }
};

class MyCalendar {
public:
    vector<period> time;

    MyCalendar() {}

    bool book(int start, int end) {
        if (time.empty()) {
            time.push_back(period(start, end));
        } else {
            for (const auto& it : time) {
                if (start < it.end && end > it.start) {
                    return false;
                }
            }
        }
        time.push_back(period(start, end));
        return true;
    }
};

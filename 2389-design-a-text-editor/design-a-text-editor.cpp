class TextEditor {
    stack<char> lef, rig;

public:
    TextEditor() {
    }

    void addText(string text) {
        for (char i : text) {
            lef.push(i);
        }
    }

    int deleteText(int k) {
        int c = 0;
        while (k-- && !lef.empty()) {
            lef.pop();
            c++;
        }
        return c;
    }

    string cursorLeft(int k) {
        while (!lef.empty() && k--) {
            rig.push(lef.top());
            lef.pop();
        }
        return cursorString();
    }

    string cursorRight(int k) {
        while (!rig.empty() && k--) {
            lef.push(rig.top());
            rig.pop();
        }
        return cursorString();
    }

    string cursorString() {
        string res = "";
        stack<char> temp = lef;
        int cnt = 10; // Assuming you want to return 10 characters
        while (!temp.empty() && cnt > 0) {
            char c = temp.top();
            temp.pop();
            res = c + res; // appending char at the beginning to reverse it
            cnt--;
        }
        return res;
    }
};
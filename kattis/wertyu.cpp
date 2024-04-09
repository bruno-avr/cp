#include "bits/stdc++.h"

using namespace std;

char convert(char c) {
    vector<string> lines(5);
    lines[0] = "1234567890-=";
    lines[1] = "QWERTYUIOP[]\\";
    lines[2] = "ASDFGHJKL;\'";
    lines[3] = "ZXCVBNM,./";
    lines[4] = "  ";
    for (auto &line : lines) {
        auto pos = line.rfind(c);
        if (pos == string::npos) continue;
        return line[pos-1];
    }
    return ' ';
}

int main()
{
    string s;
    while(getline(cin, s)) {
        for (char &c : s) {
            c = convert(c);
        }
        cout << s << endl;
    }

    return 0;
}

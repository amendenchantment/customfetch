#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

const char *get_os() {
#ifdef __APPLE__
    return "macos";
#endif
#ifdef _WIN64
    return "windows";
#endif
    return "unix";
}

int main() {
    char keywords[4][10] = {"LOGNAME", "OS", "SHELL", "COLORTERM"};
    for (char *keyword : keywords) {
        cout << "\x1b[35;5m" << keyword << ": "
             << "\x1b[0m";
        if (strcmp(keyword, "OS") == 0) {
            cout << get_os() << endl;
        } else {
            cout << getenv(keyword) << endl;
        };
    };

    return 1;
}

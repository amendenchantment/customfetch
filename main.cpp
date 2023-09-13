#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

char *get_os() {
#ifdef __APPLE__
    return const_cast<char *>("macos");
#endif
#ifdef _WIN64
    return const_cast<char *>("windows");
#endif
    return const_cast<char *>("unix");
}

int main() {
    system("./color_blocks");

    char *keywords[4] = {const_cast<char *>("LOGNAME"),
                         const_cast<char *>("OS"), const_cast<char *>("SHELL"),
                         const_cast<char *>("COLORTERM")};

    int max_index = sizeof(keywords) / sizeof(keywords[0]);
    for (char *keyword : keywords) {
        system("echo \x1b[32m");
        cout << keyword << ": ";
        system("echo \x1b[0m");
        if (strcmp(keyword, "OS") == 0) {
            cout << get_os() << endl;
        } else {
            char *retrieved_info = getenv(keyword);
            cout << retrieved_info << endl;
        };
    };

    return 1;
}

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

const char *get_os() {
#ifdef __APPLE__
    return "macos";
#endif
#ifdef _WIN64
    return "windows";
#endif
    return "unix";
}

std::string char_array_lower(char characters[]) {
    std::string stringed_chars = characters;
    std::transform(stringed_chars.begin(), stringed_chars.end(),
                   stringed_chars.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return stringed_chars;
}

int main() {
    char keywords[4][10] = {"LOGNAME", "OS", "SHELL", "COLORTERM"};
    for (auto keyword : keywords) {
        std::cout << "\x1b[35;1m" << char_array_lower(keyword) << ": "
                  << "\x1b[0m";
        if (strcmp(keyword, "OS") == 0) {
            std::cout << get_os() << std::endl;
        } else {
            std::cout << getenv(keyword) << std::endl;
        };
    };

    return 1;
}

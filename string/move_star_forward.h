#ifndef ALGORITHM_DESIGN_ANALYSIS_MOVE_STAR_FORWARD_H
#define ALGORITHM_DESIGN_ANALYSIS_MOVE_STAR_FORWARD_H

#include <iostream>
#include <cstring>

char *MoveStartForward(char *str) {
    int i = std::strlen(str) - 1;
    for (int j = i; j >= 0; j--) {
        if (str[i] != '*') {
            i--;
        } else if (str[j] != '*') {
            str[i] = str[j];
            str[j] = '*';
            i--;
        }
    }
    return str;
}

void MoveStartForwardTest() {
    char str[100] = "ab**cd**e***f";
    std::cout << MoveStartForward(str) << std::endl;
    std::strcpy(str, "abcd**asd***");
    std::cout << MoveStartForward(str) << std::endl;
    std::strcpy(str, "***abcd**asd");
    std::cout << MoveStartForward(str) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_MOVE_STAR_FORWARD_H

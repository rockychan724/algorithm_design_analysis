#ifndef ALGORITHM_DESIGN_ANALYSIS_FIND_WATER_KING_H
#define ALGORITHM_DESIGN_ANALYSIS_FIND_WATER_KING_H

#include <iostream>

// 查找“水王”，“水王”占一半以上
int FindWaterKing(const int *ID, int N) {
    int num = 0;
    int candidate;
    for (int i = 0; i < N; i++) {
        if (num == 0) {
            candidate = ID[i];
            num++;
        } else {
            if (ID[i] == candidate)
                num++;
            else
                num--;
        }
    }
    return candidate;
}

// 查找三个“水王”，每个“水王”占1/4以上
void FindMultiWaterKing(const int *ID, int N, int candidate[3]) {
    int num[3] = {0, 0, 0};
    candidate[0] = candidate[1] = candidate[2] = -1;  // 假设id都大于0
    for (int i = 0; i < N; i++) {
        if (num[0] == 0) {
            candidate[0] = ID[i];
            num[0]++;
        } else if (num[1] == 0) {
            candidate[1] = ID[i];
            num[1]++;
        } else if (num[2] == 0) {
            candidate[2] = ID[i];
            num[2]++;
        } else if (ID[i] == candidate[0]) {
            num[0]++;
        } else if (ID[i] == candidate[1]) {
            num[1]++;
        } else if (ID[i] == candidate[2]) {
            num[2]++;
        } else {
            num[0]--, num[1]--, num[2]--;
        }
    }
}

void FindWaterKingTest() {
    int ID[] = {1, 2, 3, 4, 5, 1, 2, 31, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << FindWaterKing(ID, 16) << std::endl;
    int id[] = {1, 2, 3, 4, 5, 6, 3, 2, 2, 3, 1, 2, 1, 3, 4, 1, 1, 3, 2, 3};
    int res[3];
    FindMultiWaterKing(id, 20, res);
    std::cout << res[0] << "," << res[1] << "," << res[2] << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_FIND_WATER_KING_H

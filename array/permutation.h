#ifndef ALGORITHM_DESIGN_ANALYSIS_PERMUTATION_H
#define ALGORITHM_DESIGN_ANALYSIS_PERMUTATION_H

#include <iostream>
#include <algorithm>

void Permutation(int num[], int k, int m) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            std::cout << num[i] << " ";
        std::cout << "\b\n";
    } else {
        for (int i = k; i < m; i++) {
            std::swap(num[k], num[i]);
            Permutation(num, k + 1, m);
            std::swap(num[k], num[i]);
        }
    }
}

void PermutationTest() {
    int num[] = {2, 4, 6};
//    do {
//        std::cout << num[0] << " " << num[1] << " " << num[2] << std::endl;
//    } while (std::next_permutation(num, num + 3));
//    std::cout << "===========\n";
    Permutation(num, 0, 3);
}

#endif //ALGORITHM_DESIGN_ANALYSIS_PERMUTATION_H

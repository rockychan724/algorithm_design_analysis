#ifndef ALGORITHM_DESIGN_ANALYSIS_ALIBABA_2013_H
#define ALGORITHM_DESIGN_ANALYSIS_ALIBABA_2013_H

#include <iostream>
#include <vector>

void FindAllPropertyIndex(int A[], int offset, int n, std::vector<int> &indices) {
    if (n <= 0) return;
    if (A[offset + n / 2] == offset + n / 2) {
        indices.push_back(offset + n / 2);
    }
    FindAllPropertyIndex(A, offset, n / 2, indices);
    FindAllPropertyIndex(A, offset + n / 2 + 1, n / 2 - (n + 1) % 2, indices);
}

void FindAllPropertyIndexTest() {
    int A[] = {1, 1, 2, 5, 4, 0, 6};  // {i | A[i] = i} = {1, 4, 6}
    std::vector<int> indices;
    FindAllPropertyIndex(A, 0, 7, indices);
    for (auto i: indices)
        std::cout << i << " ";
}

#endif //ALGORITHM_DESIGN_ANALYSIS_ALIBABA_2013_H

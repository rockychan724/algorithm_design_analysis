#ifndef ALGORITHM_DESIGN_ANALYSIS_ALIBABA_2013_H
#define ALGORITHM_DESIGN_ANALYSIS_ALIBABA_2013_H

#include <iostream>
#include <vector>

// Other's method: only can get one correct value, not meet the subject requirements
//int BinarySearch(int cc[], int len) {
//    int l = 0, r = len, mid;
//    while (l <= r) {
//        mid = l + ((r - l) >> 1);
//        if (mid == 0 && cc[mid] == mid) return 0;
//        if (cc[mid] < mid && cc[mid + 1] == mid + 1) return mid + 1;
//        if (cc[mid] >= mid) r = mid - 1;
//        else l = mid + 1;
//    }
//    return -1;
//}

void FindAllPropertyIndex(int A[], int offset, int n, std::vector<int> &indices) {
    if (n <= 0) return;
    if (A[offset + n / 2] == offset + n / 2) {
        indices.push_back(offset + n / 2);
    }
    FindAllPropertyIndex(A, offset, n / 2, indices);
    FindAllPropertyIndex(A, offset + n / 2 + 1, n / 2 - (n + 1) % 2, indices);
}

void FindAllPropertyIndexTest() {
    int A[] = {-2, 0, 2, 3, 4, 5, 6};  // {i | A[i] = i} = {1, 2, 4, 6}
    std::vector<int> indices;
    FindAllPropertyIndex(A, 0, 7, indices);
    for (auto i: indices)
        std::cout << i << " ";
//    std::cout << BinarySearch(A, 7) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_ALIBABA_2013_H

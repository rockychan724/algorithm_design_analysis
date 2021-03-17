#ifndef ALGORITHM_DESIGN_ANALYSIS_GET_MIN_VALUE_FROM_ARRAY_H
#define ALGORITHM_DESIGN_ANALYSIS_GET_MIN_VALUE_FROM_ARRAY_H

#include <iostream>

// 使用递归求数组 A 中的最小元素
// min(A[0, n-1]) = min(A[0, n-2], A[n-1])
//                  / 0, n=1
// 基本操作次数 N(n) =
//                  \ N(n-1) + 1, n>1
// N(n) = O(n)
int Min(int A[], int n) {
    if (n == 1) return A[0];
    else {
        int temp = Min(A, n - 1);
        if (temp <= A[n]) return temp;
        else return A[n];
    }
}

void MinTest() {
    int A[] = {1, 8, 3, 10, -5, 5, 100};
    std::cout << "Min value: " << Min(A, 7) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_GET_MIN_VALUE_FROM_ARRAY_H

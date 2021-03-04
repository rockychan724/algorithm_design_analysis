/*
 * 求数值数组中大小最接近的两个元素的差
 */
#ifndef ALGORITHM_DESIGN_ANALYSIS_MIN_DISTANCE_H
#define ALGORITHM_DESIGN_ANALYSIS_MIN_DISTANCE_H

#include <iostream>
#include <algorithm>
#include <cmath>

// 先排序，最接近的两个元素必定是相邻的
int MinDistance1(int a[], int n) {
    if (n < 2)
        return -1;
    std::sort(a, a + n);
    int min_distance = std::abs(a[0] - a[1]);
    for (int i = 1; i < n - 1; i++) {
        int d = std::abs(a[i] - a[i + 1]);
        if (d < min_distance)
            min_distance = d;
    }
    return min_distance;
}

void MinDistanceTest() {
    int a[] = {3, 7, 1, 9, 10};
    std::cout << MinDistance1(a, 5) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_MIN_DISTANCE_H

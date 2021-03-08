/*
 * 求数值数组中大小最接近的两个元素的差
 */

#ifndef ALGORITHM_DESIGN_ANALYSIS_MIN_DISTANCE_H
#define ALGORITHM_DESIGN_ANALYSIS_MIN_DISTANCE_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

// 先排序，最接近的两个元素必定是相邻的
int MinDistance1(int A[], int n) {
    if (n < 2)
        return -1;
    std::sort(A, A + n); // 如果内部排序算法为快速排序，时间复杂度为O(nlogn)
    int min_distance = std::abs(A[0] - A[1]);
    for (int i = 1; i < n - 1; i++) {
        int d = std::abs(A[i] - A[i + 1]);
        if (d < min_distance)
            min_distance = d;
    }
    return min_distance;
}

// 先求出数组中的最小值、最大值，分别对应min, max，再新建数组B[max-min+1]，
// 将原数组A的元素一一映射到B数组上（映射方式是B[A[i]-min]=A[i]-min），再求相邻的最小间距
// 该算法的时间复杂度为O(n)，空间复杂度为O(max-min)
// 以A[] = {3, 7, 1, 9, 10}为例，min=1, max=10, B[]=
//  0   1   2   3   4   5   6   7   8   9   10
//  0   -1  2   -1  -1  -1  6   -1  8   9   -1
int MinDistance2(int A[], int n) {
    if (n < 2)
        return -1;
    // get min value and max value in array A
    int min = A[0], max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < min)
            min = A[i];
        else if (A[i] > max)
            max = A[i];
    }
    if (max - min + 1 < n) // max-min+1<n说明一定有重复的元素，则最接近的两个元素的距离为0
        return 0;
    std::vector<int> B(max - min + 1, -1);
    for (int i = 0; i < n; i++) {
        int temp = A[i] - min;
        if(B[temp] != -1) // B[temp] != -1说明有两个元素的值相等，则返回0
            return 0;
        B[temp] = temp;
    }
    int min_distance = max - min;
    int len_minus_one = min_distance; // 当前连续的-1串的长度
    for (auto i : B) {
        if (i == -1)
            len_minus_one++;
        else {
            if (len_minus_one + 1 < min_distance)
                min_distance = len_minus_one + 1;
            len_minus_one = 0;
        }
    }
    return min_distance;
}

void MinDistanceTest() {
    int A1[] = {3, 7, 1, 9, 10};
    int A2[] = {9, 8, 0, 3, 6, 8};
    std::cout << MinDistance2(A1, 5) << std::endl;
    std::cout << MinDistance2(A2, 6) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_MIN_DISTANCE_H

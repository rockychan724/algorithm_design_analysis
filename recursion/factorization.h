#ifndef ALGORITHM_DESIGN_ANALYSIS_FACTORIZATION_H
#define ALGORITHM_DESIGN_ANALYSIS_FACTORIZATION_H

#include <iostream>
#include <vector>

static int total = 0;
static std::vector<std::vector<int>> result;

// IntegerDivision(n, m)表示n的最大加数不超过m的划分个数
int IntegerDivision(int n, int m) {
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return 1;
    if (m > n) return IntegerDivision(n, n);
    if (m == n) return 1 + IntegerDivision(n, n - 1);
    return IntegerDivision(n - m, m) + IntegerDivision(n, m - 1);
}

void IntegerFactorization(int n, std::vector<int> &temp) {
    if (n == 1) {
        total++;
        std::vector<int> v(temp);
        result.push_back(v);
        temp.clear();
        std::cout << "n = 1:" << std::endl;
        for (auto i : v) {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    } else {
        for (int i = n; i > 1; i--) {
            if (n % i == 0) {
                temp.push_back(i);
//                std::cout << "n = " << n << std::endl;
//                for (auto j : temp) {
//                    std::cout << j << ",";
//                }
//                std::cout << std::endl;
                IntegerFactorization(n / i, temp);
            }
        }
    }
}

void IntegerDivisionTest() {
    for (int n = 1; n < 10; n++)
        std::cout << "n = " << n << ", " << IntegerDivision(n, n) << std::endl;
}

void IntegerFactorizationTest() {
    std::vector<int> temp;
    for (int n = 2; n <= 12; n++) {
        total = 0;
        IntegerFactorization(6, temp);
        std::cout << "n = " << n << ", " << total << std::endl;
        for (auto &res : result) {
            for (auto &fac: res) {
                std::cout << fac << "X";
            }
            std::cout << std::endl;
        }
    }
}

#endif //ALGORITHM_DESIGN_ANALYSIS_FACTORIZATION_H

#ifndef ALGORITHM_DESIGN_ANALYSIS_FACTORIZATION_H
#define ALGORITHM_DESIGN_ANALYSIS_FACTORIZATION_H

#include <iostream>
#include <vector>
#include <stack>

bool can_repeat;
int total = 0;
std::vector<std::vector<int>> result;

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
        result.push_back(temp);
    } else {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                if (can_repeat) {  // 允许重复
                    temp.push_back(i);
                    IntegerFactorization(n / i, temp);
                    temp.erase(temp.end() - 1);
                } else if (temp.empty() || temp.back() <= i) {  // 不允许重复
                    temp.push_back(i);
                    IntegerFactorization(n / i, temp);
                    temp.erase(temp.end() - 1);
                }
            }
        }
    }
}

void IntegerDivisionTest() {
    for (int n = 1; n < 10; n++)
        std::cout << "n = " << n << ", " << IntegerDivision(n, n) << std::endl;
}

void IntegerFactorizationTest() {
    can_repeat = true;
    for (int n = 2; n <= 12; n++) {
        std::vector<int> temp;
        total = 0;
        result.clear();
        IntegerFactorization(n, temp);
        std::cout << "n = " << n << ", total: " << total << std::endl;
        for (auto &s : result) {
            for (auto &f : s) {
                std::cout << f << "X";
            }
            std::cout << "\b" << std::endl;
        }
    }
}

#endif //ALGORITHM_DESIGN_ANALYSIS_FACTORIZATION_H

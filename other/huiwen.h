#ifndef ALGORITHM_DESIGN_ANALYSIS_HUIWEN_H
#define ALGORITHM_DESIGN_ANALYSIS_HUIWEN_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int lcm(std::string a, std::string b) {
    int m = a.length(), n = b.length();
    std::vector<std::vector<int>> c(m+1, std::vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = std::max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    return c[m][n];
}

int Solve(std::string s) {
    std::string rs(s);
    std::reverse(rs.begin(), rs.end());
    return s.length() - lcm(s, rs);
}

void SolveTest() {
    std::cout << Solve("google") << std::endl;
    std::cout << Solve("abcda") << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_HUIWEN_H

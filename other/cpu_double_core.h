#ifndef ALGORITHM_DESIGN_ANALYSIS_CPU_DOUBLE_CORE_H
#define ALGORITHM_DESIGN_ANALYSIS_CPU_DOUBLE_CORE_H

#include <iostream>
#include <vector>
#include <algorithm>

int MinRunTime(std::vector<int> data) {
    int n = data.size();
    int sum = 0;
    std::for_each(data.begin(), data.end(), [&sum](int &i) { i /= 1024; sum += i; });
    std::vector<int> task(sum / 2);
    for (int i = 0; i < n; i++) {
        for (int j = sum / 2; j >= data[i]; j--) {
            task[j] = std::max(task[j], task[j - data[i]] + data[i]);
        }
    }
    return (sum - task[sum / 2]) * 1024;
}

void MinRunTimeTest() {
    std::vector<int> data = {3072, 3072, 7168, 3072, 1024};
    std::cout << MinRunTime(data) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_CPU_DOUBLE_CORE_H

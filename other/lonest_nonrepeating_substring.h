#ifndef ALGORITHM_DESIGN_ANALYSIS_LONEST_NONREPEATING_SUBSTRING_H
#define ALGORITHM_DESIGN_ANALYSIS_LONEST_NONREPEATING_SUBSTRING_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string LongestNonRepeatingSubstring(const std::string &src) {
    std::vector<int> bits(26, -1);
    // longest_substring 记录最长不重复子串的信息，数组的两个元素分别表示最长不重复子串的起始位置和长度
    int longest_substring[2] = {0, 0};
    int current_substring[2] = {0, 0};
    for (int i = 0; i < src.length(); i++) {
        int index = src[i] - 'a';
        if (bits[index] < 0) {
            current_substring[1]++;
            if (current_substring[1] > longest_substring[1])
                std::copy(current_substring, current_substring + 2, longest_substring);
        } else { // 一旦bits[index] >= 0，说明字符char(index)在之前出现过，更新当前子串
            current_substring[0] = bits[index] + 1;
            current_substring[1] = i - index;
        }
        bits[index] = i;
    }
    return src.substr(longest_substring[0], longest_substring[1]);
}

void LongestNonRepeatingSubstringTest() {
    std::string test_cases[] = {"absd", "abba", "abdffd", "abcdaefghij", "abcddefg", "abcdabcghysaind"};
    for (const auto &s: test_cases) {
        auto res = LongestNonRepeatingSubstring(s);
        std::cout << "Input: " << s << ", Output: " << res << ", " << res.length() << std::endl;
    }
}

#endif //ALGORITHM_DESIGN_ANALYSIS_LONEST_NONREPEATING_SUBSTRING_H

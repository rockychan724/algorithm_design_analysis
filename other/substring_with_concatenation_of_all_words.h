#ifndef ALGORITHM_DESIGN_ANALYSIS_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H
#define ALGORITHM_DESIGN_ANALYSIS_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::map<int, std::vector<std::string>> SubstringWithConcatenationOfAllWords(std::vector<std::string> L, std::string W) {
    int word_num = L.size(), word_len = L[0].length(), str_len = W.length();
    std::map<int, std::vector<std::string>> res;
    for (int i = 0; i < str_len - word_len * word_num + 1; i++) {
        std::vector<std::string> temp;
        for (int j = 0; j < word_num; j++) {
            std::string sub = W.substr(i + word_len * j, word_len);
            if (std::find(L.begin(), L.end(), sub) == L.end()) break; // sub不是L中的元素
            if (std::find(temp.begin(), temp.end(), sub) != temp.end()) break; // sub在temp中，说明当前i位置开头的子串有重复单词
            temp.push_back(sub);
        }
        if (temp.size() == L.size())
            res.insert({i, temp});
    }
    return res;
}

void SubstringWithConcatenationOfAllWordsTest() {
    const int test_num = 4;
    std::vector<std::string> L[test_num] = {{"foo",  "bar"},
                                            {"a",    "b",    "c",    "d", "e"},
                                            {"mon",  "key"},
                                            {"fooo", "barr", "ding", "wing"}};
    std::string W[test_num] = {"barfoothefoobarman", "abcdfecdba", "monkey",
                               "lingmindraboofooowingdingbarrwingmonkeypoundcake"};
    for (int i = 0; i < test_num; i++) {
        std::cout << "============================\n";
        auto res = SubstringWithConcatenationOfAllWords(L[i], W[i]);
        std::cout << "Input: W=\"" << W[i] << "\", L=[";
        std::for_each(L[i].begin(), L[i].end(), [](const std::string &s) { std::cout << "\"" << s << "\","; });
        std::cout << "\b]\nOutput:\n";
        for (auto &r: res) {
            std::cout << r.first << ", \"";
            std::for_each(r.second.begin(), r.second.end(), [](const std::string &s) { std::cout << s; });
            std::cout << "\"\n";
        }
    }
}

#endif //ALGORITHM_DESIGN_ANALYSIS_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H

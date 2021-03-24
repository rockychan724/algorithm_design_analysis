#ifndef ALGORITHM_DESIGN_ANALYSIS_BIGDATA_MULTI_H
#define ALGORITHM_DESIGN_ANALYSIS_BIGDATA_MULTI_H

#include <string>

std::string mul(std::string s1, std::string s2) {
    if (s1.length() < 10000 && s2.length() < 10000) {
        return std::to_string(std::atoi(s1.c_str()) * std::atoi(s2.c_str()));
    }
    int len1 = s1.length(), len2 = s2.length();
    std::string a = s1.substr(0, len1 / 2);
    std::string b = s1.substr(len1 / 2, len1);
    std::string c = s2.substr(0, len2);
}

#endif //ALGORITHM_DESIGN_ANALYSIS_BIGDATA_MULTI_H

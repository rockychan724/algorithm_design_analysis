#ifndef ALGORITHM_DESIGN_ANALYSIS_STAR_KING_H
#define ALGORITHM_DESIGN_ANALYSIS_STAR_KING_H

#include <iostream>

bool CanGetFarmer(int sources, int day, int i) {
    return sources >= 50 && (day - i + 1) * 8 >= 50;
}

int StarKing(int day) {
    int farmers = 5, sources = 50;
    for (int i = 1; i <= day; i++) {
        // 每天开始时判断是否用资源兑换农民
        if (CanGetFarmer(sources, day, i)) {
            int new_farmers = sources / 50;
            sources -= 50 * new_farmers;
            farmers += new_farmers;
        }
        // 每天结束时资源值增加
        sources += farmers * 8;
        std::cout << "after " << i << " days, total source is " << sources << ", farmers num is " << farmers << std::endl;
    }
    return sources;
}

void StarKingTest() {
    int day = 10;
    std::cout << "============================ day = " << day << ":\n" << StarKing(day) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_STAR_KING_H

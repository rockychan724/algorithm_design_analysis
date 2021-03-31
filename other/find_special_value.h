#ifndef ALGORITHM_DESIGN_ANALYSIS_FIND_SPECIAL_VALUE_H
#define ALGORITHM_DESIGN_ANALYSIS_FIND_SPECIAL_VALUE_H

#include <iostream>
#include <bitset>

#define ll long long

ll FindSpecialValue(ll array[], int N, int m, int n) {
    std::bitset<64> b;
    int res[64] = {0};
    for (ll i = 0; i < N; i++) {
        b = array[i];
        int j = 0;
        for (int j = 0; j < 64; j++) {
            res[j] = (res[j] + b[j]) % n;
        }
    }
    b.reset();
    for (int j = 0; j < 64; j++) {
        if (res[j] > 0) {
            b.set(j);
        }
    }
    return static_cast<ll>(b.to_ullong());
}

void FindSpecialValueTest() {
    ll array1[] = {-2, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2};
    ll array2[] = {5, 11, 5, 11, 2, 2, 11, 5};
    std::cout << FindSpecialValue(array1, 11, 1, 2) << std::endl;
    std::cout << FindSpecialValue(array2, 8, 2, 3) << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_FIND_SPECIAL_VALUE_H

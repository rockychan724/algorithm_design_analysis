/*
 * 最短过桥时间问题：夜晚有甲乙丙丁四个人，过桥时间分别是1分钟，2分钟，5分钟，10分钟，过桥需要一只手电筒，
 * 且他们只有一只手电筒，每次过桥最多只能通过两个人，两个人过桥的速度等于其中速度较慢的那个。问他们全部过桥
 * 最少要用多长时间？
 */

#ifndef ALGORITHM_DESIGN_ANALYSIS_SHORTED_BRIDGE_TIME_H
#define ALGORITHM_DESIGN_ANALYSIS_SHORTED_BRIDGE_TIME_H

#include "graph_djkstra.h"
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>


/*
 * 解题思路：在过桥的整个过程中，每个人的位置有两种状态，即桥的这边和桥的对岸，分别用0和1表示，如果起始状态
 * 用0000，那么最终状态就是1111，由此构造一个图来求解问题，每种状态对应图上的一个点，点和点之间的边（有边
 * 说明这两个点是可达的）就是由一个状态变成另一个状态的过桥时间，那么问题就变成了求解从起点到终点的最短路径。
 * 另外，题目中还有两个约束条件，每次只能最多两人过桥，过桥时要用手电筒且他们只有一个手电筒。这两个约束条件用
 * 来判断任意两个状态是否可达，为了求解方便，将手电筒看成人，加入到状态表示中，则起始状态为00000，手电筒的过
 * 桥时间看成0。五位二进制分别表示手电筒和甲乙丙丁四个人的位置。
 */
const int TIME[] = {0, 1, 2, 5, 10}; // 0表示手电筒的过桥时间
const int MAX = INT_MAX; // 两点之间的距离距离无穷大，表示两点不可达

int CalculateDistance(int i, int j) {
    if (i == j)
        return 0;
    std::bitset<5> i_(i), j_(j);
    std::bitset<5> b = i_ ^j_;
    // i_和j_的第一位值表示手电筒，故i_和j_的第一位值必须不同，因为手电筒必须过桥（不能人过桥而手电筒不过桥）；
    // 值不同的位数必须小于等于3（最多两个人过桥+手电筒过桥，不）
    int num_different = b.count(); // 表示1的数量， 例如0101和0110异或的结果是0011，则b.count()=2
    if (b[0] == 1 && num_different >= 2 && num_different <= 3) {
        int consume_time = 0;
        int move_direction = i_[0]; // i_的第一位表示手电筒的状态，那么手电筒的位置变化和人的位置变化必须是一致的
        for (size_t k = 1; k < b.size(); k++) {
            if (b.test(k)) { // b.test(k) 测试第k位是否为1，若第k位等于1，则说明第k为对应的人状态发生了变化
                if (i_[k] != move_direction) // 人的位置变化和手电筒的位置变化不一致，i无法到达j
                    return MAX;
                if (TIME[k] > consume_time)
                    consume_time = TIME[k];
            }
        }
        return consume_time;
    }
    return MAX; // 状态i无法到达状态j
}

void ConstructGraph(int **graph) {
    for (int i = 0; i < 32; i++) {
        for (int j = i; j < 32; j++) {
            graph[i][j] = CalculateDistance(i, j);
            graph[j][i] = graph[i][j];
        }
    }
}

std::string BitsetToString(int i, int j) {
    std::string name[] = {"甲", "乙", "丙", "丁"};
    std::string result = "";
    std::bitset<5> i_(i), j_(j);
    std::bitset<5> b = i_ ^j_;
    for (size_t k = 1; k < b.size(); k++) {
        if (b.test(k)) {
            result += name[k - 1];
        }
    }
    return i_[0] ? result + "返回" : result + "过桥";
}

void ShortedBridgeTimeTest() {
    int **graph; // 32 = 2^(4 + 1) 甲乙丙丁、手电筒一共有32种状态，假设没过桥是0，过了桥是1
    GraphDjkstra gd(32, graph);
    ConstructGraph(graph);
    int min_path;
    std::vector<int> path;
    gd.Dijkstra(0, 31, min_path, path);
    std::cout << "最短过桥时间：" << min_path << std::endl;
    for (size_t i = 0; i < path.size() - 1; i++) {
        std::cout << BitsetToString(path[i], path[i + 1]) << std::endl;
    }
}

void BitsetTest() {
    std::bitset<4> a(5);
    std::bitset<4> b(6);
    std::cout << a << ',' << b << std::endl;
    std::cout << (a ^ b)[0] << std::endl;
    std::cout << a[0] << ',' << b[0] << std::endl;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_SHORTED_BRIDGE_TIME_H

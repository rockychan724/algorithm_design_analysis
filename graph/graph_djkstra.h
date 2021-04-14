#ifndef ALGORITHM_DESIGN_ANALYSIS_GRAPH_DJKSTRA_H
#define ALGORITHM_DESIGN_ANALYSIS_GRAPH_DJKSTRA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>


struct Distance {
    int value;
    bool visit;
    std::vector<int> path;

    Distance() {
        value = 0;
        visit = false;
        path.clear();
    }
};


class GraphDjkstra {
private:
    int vertex_num;
    int **vertex;
    Distance *distance;
public:
    GraphDjkstra(int vertex_num_, int **&vertex_);

    ~GraphDjkstra();

    void Dijkstra(int start, int end, int &min_path, std::vector<int> &path);

};


GraphDjkstra::GraphDjkstra(int vertex_num_, int **&vertex_) : vertex_num(vertex_num_) {
    distance = new Distance[vertex_num];
    vertex = new int *[vertex_num];
    for (int i = 0; i < vertex_num; i++) {
        vertex[i] = new int[vertex_num];
        std::fill(vertex[i], vertex[i] + vertex_num, INT_MAX);
    }
    vertex_ = vertex;
}


GraphDjkstra::~GraphDjkstra() {
    delete[] distance;
    for (int i = 0; i < vertex_num; i++)
        delete[] vertex[i];
    delete[] vertex;
}


void GraphDjkstra::Dijkstra(int start, int end, int &min_path, std::vector<int> &path) {
    for (int i = 0; i < vertex_num; i++) {
        distance[i].value = vertex[start][i];
        distance[i].path.push_back(start);
        distance[i].path.push_back(i);
    }
    distance[start].value = 0;
    distance[start].visit = true;
    for (int count = 0; count < vertex_num; count++) {
        int min_index = 0;
        int min = INT_MAX;
        for (int i = 0; i < vertex_num; i++) {
            if (!distance[i].visit && distance[i].value < min) {
                min_index = i;
                min = distance[i].value;
            }
        }
        distance[min_index].visit = true;
        for (int i = 0; i < vertex_num; i++) {
            if (!distance[i].visit && vertex[min_index][i] != INT_MAX &&
                (distance[min_index].value + vertex[min_index][i] < distance[i].value)) {
                distance[i].value = distance[min_index].value + vertex[min_index][i];
                distance[i].path = distance[min_index].path;
                distance[i].path.push_back(i);
            }
        }
    }
    min_path = distance[end].value;
    path = distance[end].path;
}

#endif //ALGORITHM_DESIGN_ANALYSIS_GRAPH_DJKSTRA_H

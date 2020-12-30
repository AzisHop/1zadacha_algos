#pragma once
#include <vector>

using namespace std;

struct IGraph {
    virtual ~IGraph() = default;

    virtual void add_edge(int from, int to) = 0;

    virtual int vertices_count() const = 0;

    virtual vector<int> get_next_vertices(int vertex) const = 0;
    virtual vector<int> get_prev_vertices(int vertex) const = 0;
};

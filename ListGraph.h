#pragma once
#include <vector>
#include <cassert>
#include <queue>
#include <stack>
#include <list>
#include "IGraph.h"


class ListGraph : public IGraph {
public:
    ListGraph(size_t n);
    virtual ~ListGraph() = default;

    void add_edge(int from, int to) override;
    virtual int vertices_count() const override;
    virtual vector<int> get_next_vertices(int vertex) const override;
    virtual vector<int> get_prev_vertices(int vertex) const override;
private:
    vector<vector<int>> adjacency_lists;
};

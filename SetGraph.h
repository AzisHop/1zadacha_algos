#pragma once
#include <cassert>
#include <unordered_set>
#include <vector>
#include "IGraph.h"

class SetGraph : public IGraph {
public:
    SetGraph(const IGraph& graph);
    virtual ~SetGraph() = default;

    virtual void add_edge(int from, int to) override;
    virtual int vertices_count() const override;
    virtual vector<int> get_next_vertices(int vertex) const override;
    virtual vector<int> get_prev_vertices(int vertex) const override;
private:
    size_t vertices_number;
    vector<unordered_set<int>> out;
    vector<unordered_set<int>> in;
};

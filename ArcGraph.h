#pragma once
#include <vector>
#include <tuple>
#include "IGraph.h"

class ArcGraph : public IGraph {
public:

    ArcGraph(const IGraph& graph);
    virtual ~ArcGraph() = default;

    virtual void add_edge(int from, int to) override;
    virtual int vertices_count() const override;
    virtual vector<int> get_next_vertices(int vertex) const override;
    virtual vector<int> get_prev_vertices(int vertex) const override;

private:
    vector<pair<int, int>> parts;
    size_t vertices_number;
};

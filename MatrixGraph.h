#pragma once
#include "IGraph.h"
#include <vector>
#include <cassert>

class MatrixGraph : public IGraph
{
public:
    MatrixGraph(const IGraph& graph);
    virtual ~MatrixGraph() = default;


    virtual void add_edge(int from, int to) override;
    virtual int vertices_count() const override;
    virtual vector<int> get_next_vertices(int vertex) const override;
    virtual vector<int> get_prev_vertices(int vertex) const override;

private:
    size_t vertices_number;
    vector<vector<bool>> parts;
};


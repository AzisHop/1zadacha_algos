#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(const IGraph& graph) :
        vertices_number(graph.vertices_count()),
        parts(vertices_number)
{
    for (auto& i : parts)
        i.assign(vertices_number, false);

    for (size_t i = 0; i < vertices_number; i++) {
        auto vertices = graph.get_next_vertices(i);
        for (int j : vertices)
            add_edge(i, j);
    }
}

void MatrixGraph::add_edge(int from, int to) {
    assert(0 <= from && (size_t)(from) < parts.size());
    assert(0 <= to && (size_t)(to) < parts.size());
    parts[from][to] = true;
};

int MatrixGraph::vertices_count() const {
    return vertices_number;
};

vector<int> MatrixGraph::get_next_vertices(int vertex) const {
    assert(0 <= vertex && (size_t)(vertex) < parts.size());
    std::vector<int> vertices;
    for (size_t i = 0; i < vertices_number; i++)
        if (parts[vertex][i])
            vertices.push_back(i);
    return vertices;
}

vector<int> MatrixGraph::get_prev_vertices(int vertex) const {
    assert(0 <= vertex && (size_t)(vertex) < parts.size());
    vector<int> vertices;
    for (size_t i = 0; i < vertices_number; i++)
        if (parts[i][vertex])
            vertices.push_back(i);
    return vertices;
};
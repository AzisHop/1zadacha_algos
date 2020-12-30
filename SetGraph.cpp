#include "SetGraph.h"


SetGraph::SetGraph(const IGraph& graph) :
        vertices_number(graph.vertices_count()),
        out(vertices_number),
        in(vertices_number)
{
    for (size_t i = 0; i < vertices_number; i++) {
        auto vertices = graph.get_next_vertices(i);
        for (int j : vertices)
            add_edge(i, j);
    }
}

void SetGraph::add_edge(int from, int to) {
    out[from].insert(to);
    in[to].insert(from);
}

int SetGraph::vertices_count() const {
    return vertices_number;
}

vector<int> SetGraph::get_next_vertices(int vertex) const {
    vector<int> vertices;
    for (int i : out[vertex])
        vertices.push_back(i);
    return vertices;
}

vector<int> SetGraph::get_prev_vertices(int vertex) const {
    vector<int> vertices;
    for (int i : in[vertex])
        vertices.push_back(i);
    return vertices;
}
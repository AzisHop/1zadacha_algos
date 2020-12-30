#include "ArcGraph.h"

ArcGraph::ArcGraph(const IGraph& graph) :
        vertices_number(graph.vertices_count())
{
    for (size_t i = 0; i < vertices_number; i++) {
        auto vertices = graph.get_next_vertices(i);
        for (int j : vertices)
            add_edge(i, j);
    }
}

void ArcGraph::add_edge(int from, int to) {
    parts.push_back(std::make_pair(from, to));
}

int ArcGraph::vertices_count() const {
    return vertices_number;
}

vector<int> ArcGraph::get_next_vertices(int vertex) const {
    vector<int> vertices;
    for (const auto& e : parts)
        if (e.first == vertex)
            vertices.push_back(e.second);
    return vertices;
}

vector<int> ArcGraph::get_prev_vertices(int vertex) const {
    vector<int> vertices;
    for (const auto& e : parts)
        if (e.second == vertex)
            vertices.push_back(e.first);
    return vertices;
}
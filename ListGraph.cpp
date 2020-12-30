#include "ListGraph.h"

ListGraph::ListGraph(size_t n) : adjacency_lists(n) {

}

void ListGraph::add_edge(int from, int to) {
    assert(0 <= from && (size_t)(from) < adjacency_lists.size());
    assert(0 <= to && (size_t)(to) < adjacency_lists.size());
    adjacency_lists[from].push_back(to);
}

int ListGraph::vertices_count() const {
    return (size_t)(adjacency_lists.size());
}

vector<int> ListGraph::get_next_vertices(int vertex) const {
    assert(0 <= vertex && (size_t)(vertex) < adjacency_lists.size());
    return adjacency_lists[vertex];
}

vector<int> ListGraph::get_prev_vertices(int vertex) const {
    assert(0 <= vertex && (size_t)(vertex) < adjacency_lists.size());
    vector<int> prev_vertices;

    for (size_t from = 0; from < adjacency_lists.size(); from++) {
        for (int to : adjacency_lists[from]) {
            if (to == vertex) {
                prev_vertices.push_back(from);
            }
        }
    }
    return prev_vertices;
}
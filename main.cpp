#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void BFS(const IGraph &graph, int vertex, void(*func)(int))
{
    std::vector<bool> visited(graph.vertices_count(), false);
    std::queue<int> next_vertices;

    next_vertices.push(vertex);
    visited[vertex] = true;

    while (next_vertices.size())
    {
        int current = next_vertices.front();
        next_vertices.pop();

        func(current);

        for (int next_vertex : graph.get_next_vertices(current))
        {
            if (!visited[next_vertex])
            {
                visited[next_vertex] = true;
                next_vertices.push(next_vertex);
            }
        }
    }
}

int main() {
    ListGraph graph(6);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(1, 5);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 2);


    MatrixGraph mgraph(graph);
    SetGraph sgraph(mgraph);
    ArcGraph agraph(sgraph);

    BFS(graph, 0, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    std::cout << "<--------------------------MatrixGraph--------------------------->" << std::endl;
    BFS(mgraph, 0, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    std::cout << "<----------------------------SetGraph---------------------------->" << std::endl;
    BFS(sgraph, 0, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    std::cout << "<----------------------------ArcGraph---------------------------->" << std::endl;
    BFS(agraph, 0, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;



    return 0;
}
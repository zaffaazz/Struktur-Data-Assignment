#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    adrNode start = FindNode(G, 'A');

    ResetVisited(G);
    cout << "BFS Traversal: ";
    PrintBFS(G, start);
    cout << endl;

    ResetVisited(G);
    cout << "DFS Traversal: ";
    PrintDFS(G, start);
    cout << endl;

    return 0;
}

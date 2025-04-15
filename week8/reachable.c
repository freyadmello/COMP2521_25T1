// Graph
typedef int Vertex;
typedef Graph {
    int nV;
    int nE;
    bool edges[nV][nV]; // Adjacency matrix, directed
};

// Set
typedef int Set;
Set SetNew();
void SetAdd(Set s, void *item);
int SetContains(Set s, void *item);

// A function that returns a set fo reachable nodes from a starting vertex and graph
Set reachable(Graph g, Vertex src) {
    Set seen = SetNew();

    doReachable(g, src, seen);

    return seen;
}

// Recursive DFS
void doReachable(Graph g, Vertex v, Set seen) {
    // add this node to the set
    SetAdd(seen, v);

    // for each neighbour visit if not in set
    for (int w = 0; w < g->nV; w++) {
        // only if w is accessible by v and we havent already explored this neighbour
        if (g->edges[v][w] != 0 && !SetContains(seen, w)) {
            doReachable(g, w, seen);
        }
    }
}

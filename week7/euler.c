#include <stdbool.h>
#include <stdlib.h>

struct edge {
    int v;
    int w;
};

typedef struct {
    int nV;
    int nE;
    bool **edges; // Adjacency Matrix, undirected
} Graph;

bool isEulerPath(Graph *g, struct edge e[], int nE) {
    // Make sure graph isnt null
    assert(g != NULL);

    // ensure all provided edges are in graph
    for (int i = 0; i < nE; i++) {
        // if edge not in graph, return false
        if (g->edges[e[i].v][e[i].w] == 0) {
            return false;
        }
    }

    // check that it is a path
    for (int i = 0; i < nE - 1; i++) {
        // ensure end of current edge matches start of next edge
        if (e[i].w != e[i+1].v) {
            return false;
        }
    }

    // check all edges occur only once
    for (int i = 0; i < nE; i++) {
        for (int j = i + 1; j < nE; j++) {
            if (e[i].v == e[j].v && e[i].w == e[j].w) {
                return false;
            }
            if (e[i].v == e[j].w && e[i].w == e[j].v) {
                return false;
            }
        }
    }

    return true;
}

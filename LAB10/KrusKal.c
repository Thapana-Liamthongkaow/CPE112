#include <stdio.h>
#include <stdlib.h>

// Structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Find set of an element i (uses path compression technique)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Perform union of two sets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges based on their weights
int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Apply Kruskal's algorithm to find MST and return its weight
int KruskalMST(struct Edge edges[], int V, int E) {
    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    if (!subsets) {
        // printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    int mstWeight = 0; // Initialize result

    // Iterate through all sorted edges
    for (int i = 0, e = 0; e < V - 1; i++) {
        // Pick the smallest edge
        struct Edge nextEdge = edges[i];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            mstWeight += nextEdge.weight;
            Union(subsets, x, y);
            e++;
        }
    }

    free(subsets);
    return mstWeight;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    //in some cases that v and e is negative number
    if (V <= 0 || E <= 0) {
        // printf("Invalid input: Number of vertices and edges must be positive integers.\n");
        return 1; // Exit the program with an error code
    }

    // Allocate memory for E edges
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    if (!edges) {
        // printf("Memory allocation failed\n");
        return 1;
    }

    // Read edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Calculate MST 
    int mstWeight = KruskalMST(edges, V, E);

    // Output
    printf("%d\n", mstWeight);

    // Free allocated memory
    free(edges);

    return 0;
}

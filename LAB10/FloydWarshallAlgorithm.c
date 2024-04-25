//66070503416 Thapaan Liamthongkaow
//LAB 10.1 Floyd-Warshall Algorithms
#include <stdio.h>

#define INF 99999

//shortest path using Floyd-Warshall algorithm
void floydWarshall(int graph[][100], int n) {
    int dist[n][n];
    int i, j, k;

    //distance matrix with the given graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Printing the shortest path distance matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n); //number of vertices

    int graph[100][100];

    // Input graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) {
                graph[i][j] = INF; // If there's no edge, set it to INF
            }
        }
    }

    floydWarshall(graph, n);

    return 0;
}

#include <stdio.h>

#define MAX 100  // Maximum number of vertices

// Adjacency matrix representation of the graph
int adj[MAX][MAX];
int visited[MAX];

// Function to perform DFS
void dfs(int vertex, int n) {
    int i;
    printf("Visited %d\n", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n = 5; // Number of vertices
    int i, j, startVertex = 0;

    // Predefined adjacency matrix
    int predefinedAdj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    // Copy predefined matrix to adj
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = predefinedAdj[i][j];
        }
    }

    // Initialize all vertices as unvisited
    for (i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    // Perform DFS starting from startVertex
    dfs(startVertex, n);

    return 0;
}

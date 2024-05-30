#include <stdio.h>
#include <stdlib.h>

#define INF 99999

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
}edgeList[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

// Function to perform the Bellman-Ford algorithm
void BellmanFord(int vertices, int edges, int start) {
    int distance[vertices];

    // Step 1: Initialize distances from start to all other vertices as INFINITE
    for (int i = 0; i < vertices; i++) {
        distance[i] = INF;
    }
    distance[start] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i < vertices ; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edgeList[j].src;
            int v = edgeList[j].dest;
            int weight = edgeList[j].weight;
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles.
    for (int i = 0; i < edges; i++) {
        int u = edgeList[i].src;
        int v = edgeList[i].dest;
        int weight = edgeList[i].weight;
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the distance array
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d \t\t %d\n", i, dis
        tance[i]);
    }
}

int main() {
    int vertices = 5; // Number of vertices in the graph
    int edges = 8; // Number of edges in the graph

    

    int start = 0; // Starting vertex
    BellmanFord(vertices, edges, start);

    return 0;
}

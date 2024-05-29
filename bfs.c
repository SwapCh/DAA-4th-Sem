#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Adjacency matrix representation of the graph
int adj[MAX][MAX];
int visited[MAX];

// Queue structure for BFS
int queue[MAX];
int front = -1;
int rear = -1;

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

// Function to remove an element from the queue
int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        vertex = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

// Function to perform BFS
void bfs(int startVertex, int n) {
    int i, currentVertex;

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front != -1) {
        currentVertex = dequeue();
        printf("Visited %d\n", currentVertex);

        for (i = 0; i < n; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    bfs(startVertex, n);

    return 0;
}

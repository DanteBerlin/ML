#include <stdio.h>
#include <stdlib.h>
//  The graph is represented as an adjacency matrix G, 
// where G[i][j] holds the weight of the edge from vertex i to vertex j.
//  If G[i][j] is zero, there is no direct edge between i and j.

// The edges are stored in an array edge of pairs, 
// where each pair stores the indices of the two vertices connected by an edge. 
// This is used to simplify the edge relaxation process
int Bellman(int G[20][20], int V, int e, int edge[20][2]) {
    int i, u, v, k, dist[20], parent[20], s, flag = 1;

    for (i = 0; i < V; i++) {
        dist[i] = 1000;
        parent[i] = -1;
    }

    printf("Enter source vertex (1 to %d): ", V);
    scanf("%d", &s);
    s--;  // Convert to 0-based indexing for array access
    dist[s] = 0;

    for (i = 0; i < V - 1; i++) {
        for (k = 0; k < e; k++) {
            u = edge[k][0];
            v = edge[k][1];
            if (dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycles
    for (k = 0; k < e; k++) {
        u = edge[k][0];
        v = edge[k][1];
        if (dist[u] + G[u][v] < dist[v]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("\nShortest path distances and parents:\n");
        for (i = 0; i < V; i++) {
            printf("Vertex %d -> Cost = %d, Parent = %d\n", i + 1, dist[i], parent[i] + 1);
        }
    }

    return flag;
}

int main() {
    int V, edge[20][2], G[20][20], i, j, k = 0;

    printf("BELLMAN FORD ALGORITHM\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the graph in matrix form (0 if no edge exists):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
            if (G[i][j] != 0 && i != j) {  // Only add edges with non-zero weights
                edge[k][0] = i;
                edge[k++][1] = j;
            }
        }
    }

    if (Bellman(G, V, k, edge))
        printf("\nNo negative weight cycle exists.\n");
    else
        printf("\nNegative weight cycle exists.\n");

    return 0;
}

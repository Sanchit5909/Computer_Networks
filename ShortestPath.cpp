#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int n, graph[10][10], dist[10], visited[10] = {0};
    int src, min, u;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }

    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> src;

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        min = INF;
        u = -1;

        for (int j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "\nShortest distances from source:\n";
    for (int i = 0; i < n; i++)
        cout << "To vertex " << i << " = " << dist[i] << endl;

    return 0;
}
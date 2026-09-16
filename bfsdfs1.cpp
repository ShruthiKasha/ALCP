#include <iostream>
using namespace std;

int graph[20][20], visited[20], n;

void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start) {
    int queue[20], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter starting vertex: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS: ";
    DFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}
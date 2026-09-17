#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[100][100];

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int selected[100] = {0};

    selected[0] = 1;

    int edges = 0;
    int total = 0;

    cout << "\nEdges in MST:\n";

    while (edges < V - 1) {
        int min = INF;
        int x = -1;
        int y = -1;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min) {

                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1) {
            cout << "Graph is disconnected";
            return 0;
        }

        cout << x << " - " << y
             << " : " << min << endl;

        total += min;
        selected[y] = 1;
        edges++;
    }

    cout << "Minimum Cost = " << total << endl;

    return 0;
}
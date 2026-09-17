#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    parent[a] = b;
}

int main() {
    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    Edge edges[100];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    sort(edges, edges + E, compare);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int count = 0;
    int total = 0;

    cout << "\nEdges in MST:\n";

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v
                 << " : " << edges[i].w << endl;

            total += edges[i].w;
            unite(u, v);
            count++;
        }
    }

    cout << "Minimum Cost = " << total << endl;

    return 0;
}
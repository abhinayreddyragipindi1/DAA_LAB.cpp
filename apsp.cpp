
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[10][10];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] != 999 && a[k][j] != 999 &&
                    a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 999)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

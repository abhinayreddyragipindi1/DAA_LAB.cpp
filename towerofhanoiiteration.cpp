#include <iostream>
#include <cmath>
using namespace std;

void towerOfHanoi(int n)
{
    int totalMoves = pow(2, n) - 1;

    char rods[3] = {'A', 'B', 'C'};

    // For even number of disks, swap destination and auxiliary
    if (n % 2 == 0)
    {
        swap(rods[1], rods[2]);
    }

    for (int move = 1; move <= totalMoves; move++)
    {
        int disk = __builtin_ctz(move) + 1;

        int from = (move >> disk) % 3;
        int to = (from + 1) % 3;

        cout << "Move disk " << disk
             << " from " << rods[from]
             << " to " << rods[to] << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n);

    return 0;
}
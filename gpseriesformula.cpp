#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    double a = 1;
    double r = x;

    double sum = a * (pow(r, n + 1) - 1) / (r - 1);

    cout << "Sum = " << sum;

    return 0;
}
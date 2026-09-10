#include <iostream>
using namespace std;

void minMax(int a[], int low, int high, int &mn, int &mx)
{
    if (low == high)
    {
        mn = mx = a[low];
        return;
    }

    int mid = (low + high) / 2;

    int min1, max1, min2, max2;

    minMax(a, low, mid, min1, max1);
    minMax(a, mid + 1, high, min2, max2);

    mn = (min1 < min2) ? min1 : min2;
    mx = (max1 > max2) ? max1 : max2;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mn, mx;

    minMax(a, 0, n - 1, mn, mx);

    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx << endl;

    return 0;
}
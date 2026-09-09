#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    int bucket[100] = {0};

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Take elements from buckets in sorted order
    int k = 0;

    for (int i = 0; i < 100; i++) {
        while (bucket[i] > 0) {
            arr[k] = i;
            k++;
            bucket[i]--;
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
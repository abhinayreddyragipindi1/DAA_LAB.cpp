#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Display frequency
    for (auto x : freq) {
        cout << x.first << " : " << x.second << endl;
    }

    return 0;
}

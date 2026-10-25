

#include <iostream>
using namespace std;

int main() {
    char ch[10];
    int freq[10], n;

    cout << "Enter number of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ch[i] >> freq[i];
    }

    cout << "Huffman Codes:\n";

    while (n > 1) {
        int min1 = -1, min2 = -1;

        for (int i = 0; i < n; i++) {
            if (freq[i] != -1) {
                if (min1 == -1 || freq[i] < freq[min1]) {
                    min2 = min1;
                    min1 = i;
                }
                else if (min2 == -1 || freq[i] < freq[min2]) {
                    min2 = i;
                }
            }
        }

        cout << ch[min1] << " : 0" << endl;
        cout << ch[min2] << " : 1" << endl;

        freq[min1] = freq[min1] + freq[min2];
        freq[min2] = -1;
        ch[min1] = '*';
    }

    return 0;
}

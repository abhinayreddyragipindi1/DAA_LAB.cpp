#include <iostream>
using namespace std;

int main() {
    int n;
    int x;
    long long sum = 0, term = 1;
cout<<"enter the x\n";
cin>>x;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i <= n; i++) {
        sum += term;
        term *= x;
    }

    cout << "Sum = " << sum << endl;

    return 0;
    
}
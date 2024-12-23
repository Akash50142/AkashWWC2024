#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Function to compute factorial modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

long long minNonZeroProduct(int p) {
    int maxNum = (1 << p) - 1; // This is 2^p - 1
    long long product = factorial(maxNum);
    return product;
}

int main() {
    int p;
    cout << "Enter the value of p: ";
    cin >> p;

    long long result = minNonZeroProduct(p);
    cout << "The minimum non-zero product of the array elements is: " << result << endl;

    return 0;
}


/*

OUTPUT:


Enter the value of p: 5
The minimum non-zero product of the array elements is: 390205642

*/

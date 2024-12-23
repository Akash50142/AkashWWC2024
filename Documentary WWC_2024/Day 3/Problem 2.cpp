#include <iostream>
#include <vector>

using namespace std;

int lastRemaining(int n) {
    int left = 1, right = n;
    bool leftToRight = true; // Start with left to right
    int step = 1; // Step size for removal

    while (left < right) {
        if (leftToRight) {
            // Remove from left to right
            left += step; // Remove the first number and every other number
        } else {
            // Remove from right to left
            right -= step; // Remove the rightmost number and every other number
        }
        step *= 2; // The step doubles after each complete pass
        leftToRight = !leftToRight; // Alternate direction
    }

    return left; // The last remaining number
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = lastRemaining(n);
    cout << "The last remaining number is: " << result << endl;

    return 0;
}

/*
Output:


Enter the value of n: 5
The last remaining number is: 6

  */

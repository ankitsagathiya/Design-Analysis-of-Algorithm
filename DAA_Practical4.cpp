#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// -------------------------
// Iterative Factorial
// -------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// -------------------------
// Recursive Factorial
// -------------------------
// Time Complexity: O(n)
// Space Complexity: O(n) due to call stack
unsigned long long factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

int main() {
    int n;
    cout << "Enter a non-negative integer (e.g., 20): ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid input! Please enter a non-negative integer." << endl;
        return 1;
    }

    // Measure Iterative Execution Time
    auto startIter = high_resolution_clock::now();
    unsigned long long resIter = factorialIterative(n);
    auto endIter = high_resolution_clock::now();
    
    duration<double, nano> durationIter = endIter - startIter;

    // Measure Recursive Execution Time
    auto startRec = high_resolution_clock::now();
    unsigned long long resRec = factorialRecursive(n);
    auto endRec = high_resolution_clock::now();
    
    duration<double, nano> durationRec = endRec - startRec;

    // Display Results
    cout << "\n--- Results for " << n << "! ---" << endl;
    cout << "Iterative Result : " << resIter << endl;
    cout << "Iterative Time   : " << durationIter.count() << " ns" << endl;
    cout << "-------------------------------" << endl;
    cout << "Recursive Result : " << resRec << endl;
    cout << "Recursive Time   : " << durationRec.count() << " ns" << endl;

    return 0;
}